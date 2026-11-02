# Train Seat Allocation and Route Query Prototype

## 1. Project Overview

The Train Seat Allocation and Route Query Prototype is a C++ console-based application developed as part of the Data Structures and Algorithms-II course.

The project demonstrates how different Data Structures and Algorithms can be applied to train record management, railway route searching and seat allocation.

It combines Binary Search Trees, Graph Algorithms, Dynamic Programming, Backtracking and Branch and Bound concepts into a menu-driven application.

The project uses simulated sample data and is designed as an educational prototype. It is not connected to any live railway reservation system.

## 2. Project Objectives

- To organize train records using a Binary Search Tree.
- To represent railway stations and routes using Graph data structures.
- To calculate shortest distances between stations using Dijkstra's Algorithm.
- To optimize limited seat capacity using Dynamic Programming.
- To check feasible seat allocation using Backtracking.
- To understand the practical application of DSA concepts in railway management.

## 3. Technologies Used

- Programming Language: C++
- IDE: Visual Studio Code
- Compiler: GCC / G++
- Application Type: Console-Based Application

## 4. Data Structures and Algorithms Used

### Unit 1: Trees

**Binary Search Tree (BST)**

A Binary Search Tree is used to store train records in sorted order based on train ID.

Main operations:
- Insertion of train records.
- Inorder traversal.
- Displaying train records in sorted order.
- Searching using BST ordering.

Time Complexity:
- Average Search: O(log n)
- Average Insertion: O(log n)
- Worst Case: O(n)

### Unit 2: Graph Algorithms

A weighted graph represents railway stations and routes. Stations are represented as vertices, and routes are represented as weighted edges containing distance in kilometres.

Graph Representation:
- Adjacency List

Algorithm:
- Dijkstra's Shortest Path Algorithm.

Applications:
- Finding the shortest distance between stations.
- Identifying unreachable stations.
- Managing railway route connections.

Time Complexity:
- Dijkstra's Algorithm: O((V + E) log V)
- Adjacency List Space: O(V + E)

### Unit 3: Dynamic Programming

**0/1 Knapsack Problem**

Dynamic Programming is used to optimize seat capacity based on booking group requirements and priority values.

The algorithm selects the best combination of booking groups without exceeding the available seat capacity.

Applications:
- Seat capacity optimization.
- Priority-based selection of booking groups.

Time Complexity:
- O(n × W)

### Unit 4: Backtracking and Branch & Bound

**Backtracking**

Backtracking checks whether a required number of seats can be formed using available seat blocks.

It follows an include-or-exclude approach to explore possible combinations.

**Branch and Bound**

Branch and Bound is studied as a related optimization technique but is not implemented in the current version.

Application:
- Checking feasible seat allocation.
- Exploring valid seat combinations.

Backtracking Worst-Case Time Complexity:
- O(2^n)

### Unit 5: Advanced Data Structures

Advanced Data Structures studied conceptually include:

- AVL Trees
- Red-Black Trees
- B-Trees
- B+ Trees

These structures are discussed as possible approaches for managing larger datasets. They are not implemented as separate modules in the current version.

## 5. Main Features

- Train record management using BST.
- Sorted display of train records.
- Railway station and route representation.
- Shortest route calculation using Dijkstra's Algorithm.
- Seat capacity optimization using 0/1 Knapsack.
- Seat availability checking using Backtracking.
- Menu-driven console interface.

## 6. Project Structure

The project is maintained in a GitHub repository and organized as follows:

```text
train-seat-allocation-route-query/
│
├── main.cpp
│
└── README.md
```

The main.cpp file serves as the entry point of the application. It contains the different algorithm implementations and the menu-driven program logic, organized into sections for each unit.

## 7. Sample Test Results

| Module | Test Case | Expected Result |
|---|---|---|
| BST | Insert IDs 101, 105, 102 | Sorted records: 101, 102, 105 |
| Graph + Dijkstra | Four-station graph | Distances: 0, 12, 30, 38 km |
| 0/1 Knapsack | Capacity 50 | Maximum value: 220 |
| Backtracking | Blocks 10, 20, 15, 5; required 25 | Allocation possible: YES |
| Menu | Invalid option | Invalid Option! Try again. |

## 8. How to Compile and Run

Make sure a C++ compiler (G++) is installed.

### Step 1: Compile

```bash
g++ main.cpp -o train_app
```

### Step 2: Run on macOS / Linux

```bash
./train_app
```

### Step 3: Run on Windows

```bash
train_app.exe
```

## 9. Project Limitations

- Uses small simulated datasets.
- Does not connect to live railway databases.
- Does not provide online ticket booking or payment.
- Does not provide real-time train tracking.
- Uses fixed sample inputs in the current prototype.

## 10. Future Improvements

- Add BST search and deletion operations.
- Implement self-balancing trees for larger datasets.
- Allow users to enter train, station and seat information.
- Add BFS, DFS, Bellman-Ford and Floyd-Warshall route options.
- Implement Branch and Bound for larger optimization problems.
- Integrate database storage.
- Develop a graphical user interface.
- Test the application with larger datasets.

## 11. Conclusion

The Train Seat Allocation and Route Query Prototype demonstrates how Data Structures and Algorithms can be applied to railway management problems.

It combines BST, Graph Algorithms, Dijkstra's Algorithm, Dynamic Programming and Backtracking in a single C++ console application.

The project provides practical understanding of algorithm selection, time complexity, problem-solving and C++ programming.

## 12. Author Information

**Name:** Abhishek Verma

**Branch:** BTech CSE-A

**College:** Noida Institute of Engineering and Technology (NIET), Greater Noida

**Course:** Data Structures and Algorithms - II

**Course Code:** CCSE0301

**Faculty:** Mr. Shamshad Ali

## 13. GitHub Repository

Project Source Code:

https://github.com/av6938889-bit/train-seat-allocation-route-query

---

Developed as an academic PBL project at NIET Greater Noida.
