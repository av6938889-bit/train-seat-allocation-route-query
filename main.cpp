#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

/*
   DSA PBL PROJECT
   Project: Train Seat Allocation and Route Query Prototype

   Unit 1 - Trees:
   1. Binary Search Tree (BST)
   2. AVL Tree
   3. Heap / Max Heap
   4. Tree Traversal

   Unit 2 - Graphs:
   5. Graph
   6. Adjacency Matrix
   7. Adjacency List

   This is a prototype based only on the concepts identified
   in the PBL report.
*/

// ---------------- Passenger Record ----------------
struct Passenger {
    int id;
    string name;
    int priority;
};

// ---------------- 1. Binary Search Tree ----------------
struct BSTNode {
    Passenger data;
    BSTNode *left, *right;

    BSTNode(Passenger p) {
        data = p;
        left = right = nullptr;
    }
};

class PassengerBST {
    BSTNode* root = nullptr;

    BSTNode* insert(BSTNode* node, Passenger p) {
        if (node == nullptr)
            return new BSTNode(p);

        if (p.id < node->data.id)
            node->left = insert(node->left, p);
        else if (p.id > node->data.id)
            node->right = insert(node->right, p);

        return node;
    }

    BSTNode* search(BSTNode* node, int id) {
        if (node == nullptr || node->data.id == id)
            return node;

        if (id < node->data.id)
            return search(node->left, id);

        return search(node->right, id);
    }

    void inorder(BSTNode* node) {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << "Passenger ID: " << node->data.id
             << " | Name: " << node->data.name << endl;
        inorder(node->right);
    }

public:
    void insert(Passenger p) {
        root = insert(root, p);
    }

    void searchPassenger(int id) {
        BSTNode* result = search(root, id);

        if (result)
            cout << "Passenger found: "
                 << result->data.id << " - "
                 << result->data.name << endl;
        else
            cout << "Passenger not found." << endl;
    }

    void showInorder() {
        cout << "\n--- BST Inorder Traversal ---\n";
        inorder(root);
    }
};

// ---------------- 2. AVL Tree ----------------
struct AVLNode {
    Passenger data;
    AVLNode *left, *right;
    int height;

    AVLNode(Passenger p) {
        data = p;
        left = right = nullptr;
        height = 1;
    }
};

class PassengerAVL {
    AVLNode* root = nullptr;

    int height(AVLNode* node) {
        return node ? node->height : 0;
    }

    int balanceFactor(AVLNode* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* temp = x->right;

        x->right = y;
        y->left = temp;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* temp = y->left;

        y->left = x;
        x->right = temp;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    AVLNode* insert(AVLNode* node, Passenger p) {
        if (node == nullptr)
            return new AVLNode(p);

        if (p.id < node->data.id)
            node->left = insert(node->left, p);
        else if (p.id > node->data.id)
            node->right = insert(node->right, p);
        else
            return node;

        node->height =
            1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        // LL Case
        if (balance > 1 && p.id < node->left->data.id)
            return rightRotate(node);

        // RR Case
        if (balance < -1 && p.id > node->right->data.id)
            return leftRotate(node);

        // LR Case
        if (balance > 1 && p.id > node->left->data.id) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL Case
        if (balance < -1 && p.id < node->right->data.id) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void preorder(AVLNode* node) {
        if (node == nullptr)
            return;

        cout << node->data.id << " ";
        preorder(node->left);
        preorder(node->right);
    }

public:
    void insert(Passenger p) {
        root = insert(root, p);
    }

    void showPreorder() {
        cout << "\n--- AVL Preorder Traversal ---\n";
        preorder(root);
        cout << endl;
    }
};

// ---------------- 3. Max Heap ----------------
struct BookingRequest {
    int passengerId;
    string name;
    int priority;

    bool operator<(const BookingRequest& other) const {
        return priority < other.priority;
    }
};

class BookingMaxHeap {
    priority_queue<BookingRequest> heap;

public:
    void addRequest(int id, string name, int priority) {
        heap.push({id, name, priority});
    }

    bool empty() {
        return heap.empty();
    }

    BookingRequest getHighestPriority() {
        BookingRequest request = heap.top();
        heap.pop();
        return request;
    }

    void showRequests() {
        if (heap.empty()) {
            cout << "No pending booking requests.\n";
            return;
        }

        priority_queue<BookingRequest> copy = heap;

        cout << "\n--- Booking Requests by Priority ---\n";

        while (!copy.empty()) {
            BookingRequest r = copy.top();
            copy.pop();

            cout << "Passenger ID: " << r.passengerId
                 << " | Name: " << r.name
                 << " | Priority: " << r.priority << endl;
        }
    }
};

// ---------------- 4. Train Seat Allocation ----------------
class Train {
    int totalSeats;
    vector<bool> booked;

public:
    Train(int seats) {
        totalSeats = seats;
        booked.resize(seats + 1, false);
    }

    int allocateSeat() {
        for (int i = 1; i <= totalSeats; i++) {
            if (!booked[i]) {
                booked[i] = true;
                return i;
            }
        }

        return -1;
    }

    void showSeats() {
        cout << "\n--- Seat Status ---\n";

        for (int i = 1; i <= totalSeats; i++) {
            cout << "Seat " << i << ": "
                 << (booked[i] ? "Booked" : "Available")
                 << endl;
        }
    }
};

// ---------------- 5. Graph + Adjacency Matrix/List ----------------
class RouteGraph {
    int n;
    vector<string> stations;
    vector<vector<int>> matrix;
    vector<vector<int>> adjacencyList;

public:
    RouteGraph(vector<string> names) {
        stations = names;
        n = stations.size();

        matrix.resize(n, vector<int>(n, 0));
        adjacencyList.resize(n);
    }

    void addRoute(int u, int v) {
        if (u < 0 || v < 0 || u >= n || v >= n || u == v)
            return;

        // Undirected route
        matrix[u][v] = 1;
        matrix[v][u] = 1;

        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    void showMatrix() {
        cout << "\n--- Adjacency Matrix ---\n";

        cout << "          ";
        for (string s : stations)
            cout << s << " ";

        cout << endl;

        for (int i = 0; i < n; i++) {
            cout << stations[i] << " ";

            if (stations[i].length() < 9)
                cout << "\t";

            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << "        ";

            cout << endl;
        }
    }

    void showList() {
        cout << "\n--- Adjacency List ---\n";

        for (int i = 0; i < n; i++) {
            cout << stations[i] << " -> ";

            for (int v : adjacencyList[i])
                cout << stations[v] << " ";

            cout << endl;
        }
    }

    void routeQuery(int source, int destination) {
        if (source < 0 || destination < 0 ||
            source >= n || destination >= n) {
            cout << "Invalid station number.\n";
            return;
        }

        if (matrix[source][destination] == 1) {
            cout << "Direct route exists: "
                 << stations[source] << " -> "
                 << stations[destination] << endl;
        } else {
            cout << "No direct route between "
                 << stations[source] << " and "
                 << stations[destination] << endl;
        }
    }
};

// ---------------- Main Program ----------------
int main() {

    cout << "============================================\n";
    cout << " TRAIN SEAT ALLOCATION AND ROUTE QUERY\n";
    cout << "              PROTOTYPE\n";
    cout << "============================================\n";

    // Sample passenger records
    Passenger p1 = {103, "Rahul", 2};
    Passenger p2 = {101, "Amit", 5};
    Passenger p3 = {105, "Neha", 3};
    Passenger p4 = {102, "Priya", 4};
    Passenger p5 = {104, "Ravi", 1};

    vector<Passenger> passengers =
        {p1, p2, p3, p4, p5};

    // ==========================================
    // UNIT 1 - TREES
    // ==========================================

    // Binary Search Tree
    PassengerBST bst;

    for (Passenger p : passengers)
        bst.insert(p);

    bst.showInorder();

    cout << "\nSearching Passenger ID 102:\n";
    bst.searchPassenger(102);

    // AVL Tree
    PassengerAVL avl;

    for (Passenger p : passengers)
        avl.insert(p);

    avl.showPreorder();

    // ==========================================
    // UNIT 1 - MAX HEAP + SEAT ALLOCATION
    // ==========================================

    BookingMaxHeap bookingQueue;

    bookingQueue.addRequest(103, "Rahul", 2);
    bookingQueue.addRequest(101, "Amit", 5);
    bookingQueue.addRequest(105, "Neha", 3);
    bookingQueue.addRequest(102, "Priya", 4);

    bookingQueue.showRequests();

    // Train has 4 seats
    Train train(4);

    cout << "\n--- Seat Allocation According to Priority ---\n";

    while (!bookingQueue.empty()) {
        BookingRequest request =
            bookingQueue.getHighestPriority();

        int seatNumber = train.allocateSeat();

        if (seatNumber != -1) {
            cout << request.name
                 << " (Priority " << request.priority << ")"
                 << " -> Seat " << seatNumber << endl;
        } else {
            cout << request.name
                 << " -> Waiting List (No Seat Available)"
                 << endl;
        }
    }

    train.showSeats();

    // ==========================================
    // UNIT 2 - GRAPH
    // ==========================================

    vector<string> stations = {
        "Delhi",
        "Kanpur",
        "Lucknow",
        "Prayagraj",
        "Varanasi"
    };

    RouteGraph graph(stations);

    // Add railway connections
    graph.addRoute(0, 1); // Delhi - Kanpur
    graph.addRoute(1, 2); // Kanpur - Lucknow
    graph.addRoute(1, 3); // Kanpur - Prayagraj
    graph.addRoute(3, 4); // Prayagraj - Varanasi
    graph.addRoute(2, 4); // Lucknow - Varanasi

    graph.showMatrix();
    graph.showList();

    // Route queries
    cout << "\n--- Route Query ---\n";

    // Delhi -> Kanpur
    graph.routeQuery(0, 1);

    // Delhi -> Varanasi
    graph.routeQuery(0, 4);

    cout << "\n============================================\n";
    cout << "              END OF PROTOTYPE\n";
    cout << "============================================\n";

    return 0;
}
