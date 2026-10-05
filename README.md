# Train Seat Allocation and Route Query Prototype

DSA-II PBL Progress Review II companion project for **Abhishek Verma**.

## Unit/Module concepts demonstrated

### Unit 2 - Graphs
- Adjacency List and Adjacency Matrix
- BFS, DFS and Connected Components
- Prim's and Kruskal's Minimum Spanning Tree
- Warshall Transitive Closure
- Dijkstra shortest path
- Floyd-Warshall all-pairs shortest path

### Unit 3 - Dynamic Programming
- 0/1 Knapsack for seat allocation
- Longest Common Subsequence for station-sequence matching
- Resource Allocation for limited resources

### Unit 4 - Backtracking and Branch & Bound
- Sum of Subsets
- Graph Coloring
- Branch and Bound for constrained seat allocation

Topics such as Matrix Chain Multiplication, DAG/Bellman-Ford, TSP, N-Queen and Hamiltonian Cycle are kept out of the working prototype because they are not directly required by the current train seat-allocation and route-query scope.

## Requirements

- C++17 compiler (g++ or clang++)

## Run on macOS / Linux

```bash
g++ -std=c++17 -O2 main.cpp -o train_app
./train_app
```

## Suggested GitHub structure

```text
train-seat-allocation-route-query/
├── main.cpp
├── README.md
├── data/
│   └── sample_data.txt
├── docs/
│   └── output_notes.txt
└── screenshots/
    └── (add your actual terminal screenshots here)
```

Run the program before submission and add screenshots of the outputs you actually obtain.
