#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

const int INF = 1e9;

struct BookingRequest {
    string name;
    int seats;
    int score;
};

struct Edge {
    int u, v, w;
};

class DSU {
    vector<int> parent, rankv;
public:
    explicit DSU(int n) : parent(n), rankv(n, 0) { iota(parent.begin(), parent.end(), 0); }
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) ++rankv[a];
        return true;
    }
};

class TrainGraph {
    int n;
    vector<string> station;
    vector<vector<pair<int,int>>> adj;
    vector<vector<int>> matrix;
    vector<Edge> edges;

public:
    explicit TrainGraph(const vector<string>& names)
        : n((int)names.size()), station(names), adj(n), matrix(n, vector<int>(n, INF)) {
        for (int i = 0; i < n; ++i) matrix[i][i] = 0;
    }

    void addEdge(int u, int v, int w) {
        if (u < 0 || v < 0 || u >= n || v >= n || w < 0) return;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        matrix[u][v] = matrix[v][u] = min(matrix[u][v], w);
        edges.push_back({u, v, w});
    }

    void printAdjList() const {
        cout << "\nAdjacency List\n";
        for (int i = 0; i < n; ++i) {
            cout << station[i] << ": ";
            for (auto [v, w] : adj[i]) cout << station[v] << "(" << w << ") ";
            cout << "\n";
        }
    }

    void printAdjMatrix() const {
        cout << "\nAdjacency Matrix (-1 means no direct edge)\n\t";
        for (const auto& s : station) cout << s.substr(0, 4) << "\t";
        cout << "\n";
        for (int i = 0; i < n; ++i) {
            cout << station[i].substr(0, 4) << "\t";
            for (int j = 0; j < n; ++j) cout << (matrix[i][j] >= INF ? -1 : matrix[i][j]) << "\t";
            cout << "\n";
        }
    }

    void bfs(int start) const {
        vector<bool> vis(n, false);
        queue<int> q;
        vis[start] = true; q.push(start);
        cout << "BFS from " << station[start] << ": ";
        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << station[u] << " ";
            for (auto [v, _] : adj[u]) if (!vis[v]) { vis[v] = true; q.push(v); }
        }
        cout << "\n";
    }

    void dfsUtil(int u, vector<bool>& vis) const {
        vis[u] = true;
        cout << station[u] << " ";
        for (auto [v, _] : adj[u]) if (!vis[v]) dfsUtil(v, vis);
    }

    void dfs(int start) const {
        vector<bool> vis(n, false);
        cout << "DFS from " << station[start] << ": ";
        dfsUtil(start, vis);
        cout << "\n";
    }

    int connectedComponents() const {
        vector<bool> vis(n, false);
        int count = 0;
        function<void(int)> go = [&](int u) {
            vis[u] = true;
            for (auto [v, _] : adj[u]) if (!vis[v]) go(v);
        };
        for (int i = 0; i < n; ++i) if (!vis[i]) { ++count; go(i); }
        return count;
    }

    void dijkstra(int src, int dst) const {
        vector<int> dist(n, INF), parent(n, -1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[src] = 0; pq.push({0, src});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;
            for (auto [v, w] : adj[u]) if (dist[v] > d + w) {
                dist[v] = d + w; parent[v] = u; pq.push({dist[v], v});
            }
        }
        cout << "\nDijkstra shortest route: " << station[src] << " -> " << station[dst] << "\n";
        if (dist[dst] >= INF) { cout << "No route found.\n"; return; }
        vector<int> path;
        for (int v = dst; v != -1; v = parent[v]) path.push_back(v);
        reverse(path.begin(), path.end());
        for (size_t i = 0; i < path.size(); ++i) cout << (i ? " -> " : "") << station[path[i]];
        cout << "\nMinimum distance = " << dist[dst] << " units\n";
    }

    void primMST() const {
        vector<int> key(n, INF), parent(n, -1);
        vector<bool> used(n, false);
        key[0] = 0;
        int total = 0;
        cout << "\nPrim MST edges\n";
        for (int step = 0; step < n; ++step) {
            int u = -1;
            for (int i = 0; i < n; ++i) if (!used[i] && (u == -1 || key[i] < key[u])) u = i;
            if (u == -1) break;
            used[u] = true;
            if (parent[u] != -1) { cout << station[parent[u]] << " - " << station[u] << " : " << key[u] << "\n"; total += key[u]; }
            for (auto [v, w] : adj[u]) if (!used[v] && w < key[v]) { key[v] = w; parent[v] = u; }
        }
        cout << "Total MST weight = " << total << "\n";
    }

    void kruskalMST() const {
        vector<Edge> es = edges;
        sort(es.begin(), es.end(), [](const Edge& a, const Edge& b){ return a.w < b.w; });
        DSU dsu(n);
        int total = 0, taken = 0;
        cout << "\nKruskal MST edges\n";
        for (auto e : es) if (dsu.unite(e.u, e.v)) {
            cout << station[e.u] << " - " << station[e.v] << " : " << e.w << "\n";
            total += e.w; ++taken;
            if (taken == n - 1) break;
        }
        cout << "Total MST weight = " << total << "\n";
    }

    vector<vector<int>> warshallTransitiveClosure() const {
        vector<vector<int>> reach(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) for (auto [v, _] : adj[i]) reach[i][v] = 1;
        for (int i = 0; i < n; ++i) reach[i][i] = 1;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
        return reach;
    }

    void printTransitiveClosure() const {
        auto r = warshallTransitiveClosure();
        cout << "\nWarshall Transitive Closure (1 = reachable)\n";
        for (auto& row : r) { for (int x : row) cout << x << ' '; cout << '\n'; }
    }

    void floydWarshall() const {
        auto d = matrix;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (d[i][k] < INF && d[k][j] < INF)
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        cout << "\nFloyd-Warshall all-pairs shortest distances\n";
        for (auto& row : d) { for (int x : row) cout << (x >= INF ? -1 : x) << '\t'; cout << '\n'; }
    }
};

vector<int> knapsackDP(const vector<BookingRequest>& a, int capacity, int& bestScore) {
    vector<int> dp(capacity + 1, 0);
    vector<vector<int>> take(a.size() + 1, vector<int>(capacity + 1, 0));
    for (size_t i = 1; i <= a.size(); ++i) {
        for (int c = capacity; c >= a[i-1].seats; --c) {
            if (dp[c - a[i-1].seats] + a[i-1].score > dp[c]) {
                dp[c] = dp[c - a[i-1].seats] + a[i-1].score;
                take[i][c] = 1;
            }
        }
    }
    bestScore = dp[capacity];
    vector<int> chosen;
    int c = capacity;
    for (int i = (int)a.size(); i >= 1; --i) {
        bool can = a[i-1].seats <= c && take[i][c];
        if (can) { chosen.push_back(i-1); c -= a[i-1].seats; }
    }
    reverse(chosen.begin(), chosen.end());
    return chosen;
}

int lcsLength(const vector<string>& a, const vector<string>& b) {
    int m = (int)a.size(), n = (int)b.size();
    vector<int> prev(n+1), cur(n+1);
    for (int i = 1; i <= m; ++i) {
        fill(cur.begin(), cur.end(), 0);
        for (int j = 1; j <= n; ++j) cur[j] = (a[i-1] == b[j-1]) ? prev[j-1] + 1 : max(prev[j], cur[j-1]);
        swap(prev, cur);
    }
    return prev[n];
}

int resourceAllocation(const vector<vector<int>>& value) {
    // value[resource][option] -> maximum total score by assigning one option per resource.
    int R = (int)value.size();
    if (!R) return 0;
    vector<int> dp(value[0].size(), -INF), next(value[0].size(), -INF);
    for (int j = 0; j < (int)value[0].size(); ++j) dp[j] = value[0][j];
    for (int r = 1; r < R; ++r) {
        fill(next.begin(), next.end(), -INF);
        for (int cur = 0; cur < (int)value[r].size(); ++cur)
            for (int prev = 0; prev < (int)dp.size(); ++prev)
                next[cur] = max(next[cur], dp[prev] + value[r][cur]);
        dp.swap(next);
    }
    return *max_element(dp.begin(), dp.end());
}

struct BBState { int bestScore = -1; vector<int> chosen; };

void bbSearch(const vector<BookingRequest>& a, const vector<int>& order, int pos, int capacity,
              int used, int score, vector<int>& chosen, BBState& best) {
    if (used > capacity) return;
    if (pos == (int)order.size()) {
        if (score > best.bestScore) best = {score, chosen};
        return;
    }
    double bound = score;
    int remaining = capacity - used;
    for (int k = pos; k < (int)order.size() && remaining > 0; ++k) {
        const auto& x = a[order[k]];
        if (x.seats <= remaining) { bound += x.score; remaining -= x.seats; }
        else { bound += (double)x.score * remaining / x.seats; remaining = 0; }
    }
    if (bound <= best.bestScore) return;

    chosen.push_back(order[pos]);
    bbSearch(a, order, pos + 1, capacity, used + a[order[pos]].seats,
             score + a[order[pos]].score, chosen, best);
    chosen.pop_back();
    bbSearch(a, order, pos + 1, capacity, used, score, chosen, best);
}

vector<int> branchAndBound(const vector<BookingRequest>& a, int capacity, int& bestScore) {
    vector<int> order(a.size()); iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j){
        return (double)a[i].score / a[i].seats > (double)a[j].score / a[j].seats;
    });
    BBState best;
    vector<int> chosen;
    bbSearch(a, order, 0, capacity, 0, 0, chosen, best);
    bestScore = best.bestScore;
    return best.chosen;
}

bool graphColoringUtil(int v, int m, const vector<vector<int>>& g, vector<int>& color) {
    if (v == (int)g.size()) return true;
    for (int c = 1; c <= m; ++c) {
        bool safe = true;
        for (int u = 0; u < (int)g.size(); ++u) if (g[v][u] && color[u] == c) { safe = false; break; }
        if (safe) {
            color[v] = c;
            if (graphColoringUtil(v + 1, m, g, color)) return true;
            color[v] = 0;
        }
    }
    return false;
}

void subsetSumUtil(const vector<int>& a, int idx, int target, int sum, vector<int>& cur) {
    if (sum == target) {
        cout << "{";
        for (size_t i = 0; i < cur.size(); ++i) cout << (i ? ", " : "") << cur[i];
        cout << "}\n"; return;
    }
    if (idx == (int)a.size() || sum > target) return;
    cur.push_back(a[idx]);
    subsetSumUtil(a, idx + 1, target, sum + a[idx], cur);
    cur.pop_back();
    subsetSumUtil(a, idx + 1, target, sum, cur);
}

void printAllocation(const string& title, const vector<BookingRequest>& a, const vector<int>& chosen, int score) {
    int seats = 0;
    cout << "\n" << title << "\n";
    for (int i : chosen) { cout << "Request " << a[i].name << ": " << a[i].seats << " seats, score " << a[i].score << "\n"; seats += a[i].seats; }
    cout << "Total seats = " << seats << "\nTotal score = " << score << "\n";
}

int main() {
    cout << "TRAIN SEAT ALLOCATION AND ROUTE QUERY PROTOTYPE\n";
    cout << "DSA-II PBL Progress Review 2 Prototype\n";

    vector<string> stations = {"Delhi", "Lucknow", "Kanpur", "Prayagraj", "Varanasi", "Gorakhpur"};
    TrainGraph graph(stations);
    graph.addEdge(0, 2, 5); graph.addEdge(0, 1, 7); graph.addEdge(2, 1, 3); graph.addEdge(2, 3, 6);
    graph.addEdge(1, 3, 5); graph.addEdge(1, 5, 8); graph.addEdge(3, 4, 2); graph.addEdge(3, 5, 7); graph.addEdge(4, 5, 9);

    vector<BookingRequest> requests = {{"A",2,90},{"B",3,80},{"C",1,35},{"D",2,70},{"E",4,120}};

    while (true) {
        cout << "\nMenu\n"
             << "1. Adjacency List\n"
             << "2. Adjacency Matrix\n"
             << "3. BFS / DFS / Connected Components\n"
             << "4. Prim / Kruskal MST\n"
             << "5. Dijkstra shortest route\n"
             << "6. Warshall Transitive Closure\n"
             << "7. Floyd-Warshall all-pairs shortest paths\n"
             << "8. DP 0/1 Knapsack seat allocation\n"
             << "9. LCS station-sequence matching\n"
             << "10. DP Resource Allocation\n"
             << "11. Sum of Subsets (Backtracking)\n"
             << "12. Graph Coloring (Backtracking)\n"
             << "13. Branch and Bound seat allocation\n"
             << "0. Exit\nChoice: ";
        int choice; if (!(cin >> choice)) return 0;
        if (choice == 0) break;
        switch (choice) {
            case 1: graph.printAdjList(); break;
            case 2: graph.printAdjMatrix(); break;
            case 3: graph.bfs(0); graph.dfs(0); cout << "Connected components = " << graph.connectedComponents() << "\n"; break;
            case 4: graph.primMST(); graph.kruskalMST(); break;
            case 5: graph.dijkstra(0, 4); break;
            case 6: graph.printTransitiveClosure(); break;
            case 7: graph.floydWarshall(); break;
            case 8: { int score; auto chosen = knapsackDP(requests, 5, score); printAllocation("0/1 Knapsack DP (capacity = 5 seats)", requests, chosen, score); break; }
            case 9: { vector<string> wanted={"Delhi","Kanpur","Prayagraj","Varanasi"}; vector<string> train={"Delhi","Kanpur","Lucknow","Prayagraj","Varanasi"}; cout << "LCS length = " << lcsLength(wanted, train) << "\n"; break; }
            case 10: { vector<vector<int>> value={{8,6,7},{7,9,5},{6,8,10}}; cout << "Maximum allocation score = " << resourceAllocation(value) << "\n"; break; }
            case 11: { vector<int> set={10,7,5,18,12,20,15}, cur; cout << "Subsets with sum 35:\n"; subsetSumUtil(set,0,35,0,cur); break; }
            case 12: { const int V=4,M=3; vector<vector<int>> g(V,vector<int>(V)); auto add=[&](int u,int v){g[u][v]=g[v][u]=1;}; add(0,1);add(0,2);add(1,2);add(1,3); vector<int> color(V); cout << "Graph Coloring:\n"; if(graphColoringUtil(0,M,g,color)) for(int i=0;i<V;++i) cout << "Group "<<char('A'+i)<<" -> color "<<color[i]<<"\n"; else cout<<"No valid coloring\n"; break; }
            case 13: { int score; auto chosen=branchAndBound(requests,5,score); printAllocation("Branch and Bound seat allocation (capacity = 5 seats)",requests,chosen,score); break; }
            default: cout << "Invalid choice.\n";
        }
    }
    cout << "Program ended.\n";
    return 0;
}
