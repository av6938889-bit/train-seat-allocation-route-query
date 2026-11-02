# Train Seat Allocation and Route Query Prototype

## 1. Project Overview

The Train Seat Allocation and Route Query Prototype is a C++-based console application developed as part of the Data Structures and Algorithms-II course.

The project demonstrates the practical application of different data structures and algorithms in railway management, including train record management, shortest route calculation, seat capacity optimization and feasible seat allocation.

The application is organized into separate modules to maintain a structured and understandable project architecture.

## 2. Project Objectives

- To manage train records using a Binary Search Tree.
- To represent railway stations and routes using Graph data structures.
- To find shortest distances between stations using Dijkstra's Algorithm.
- To optimize seat capacity using Dynamic Programming.
- To check feasible seat allocation using Backtracking.
- To demonstrate the practical application of DSA concepts using C++.

## 3. Technologies Used

- Programming Language: C++
- Standard: C++17
- Compiler: GCC / G++
- IDE: Visual Studio Code
- Version Control: Git and GitHub

## 4. Data Structures and Algorithms Implemented

### Unit 1: Trees

**Binary Search Tree (BST)**

A Binary Search Tree is used to organize train records according to their Train ID.

Operations:
- Insertion of train records.
- Searching train records.
- Inorder traversal.
- Displaying train records in sorted order.
- Handling duplicate Train IDs.

Time Complexity:
- Average Insertion: O(log n)
- Average Search: O(log n)
- Worst Case: O(n)

### Unit 2: Graph Algorithms

**Weighted Graph using Adjacency List**

Railway stations are represented as vertices, while railway routes are represented as weighted edges containing distances.

Algorithm:
- Dijkstra's Shortest Path Algorithm.
- Min-Heap Priority Queue.

Applications:
- Finding shortest distances between stations.
- Representing railway connectivity.
- Identifying unreachable stations.

Time Complexity:
- Dijkstra's Algorithm: O((V + E) log V)
- Space Complexity: O(V + E)

### Unit 3: Dynamic Programming

**0/1 Knapsack Problem**

Dynamic Programming is used to solve the 0/1 Knapsack problem by selecting items with maximum total value without exceeding the given capacity.

Applications:
- Seat capacity optimization.
- Resource allocation.
- Maximizing total selection value.

Time Complexity:
- O(n × W)

### Unit 4: Backtracking

**Seat Allocation using Backtracking**

Backtracking is used to check whether a required number of seats can be allocated by selecting suitable available seat blocks.

The algorithm follows an include-or-exclude approach to explore possible combinations.

Applications:
- Checking feasible seat combinations.
- Selecting available seat blocks.
- Exploring possible allocation solutions.

Worst-Case Time Complexity:
- O(2^n)

## 5. Main Project Features

- Train record insertion and searching.
- Sorted train record display.
- Railway station connectivity representation.
- Shortest route distance calculation.
- Dynamic Programming-based capacity optimization.
- Backtracking-based seat allocation checking.
- Menu-driven console interface.

## 6. Project Structure

The project source code is maintained in a modular folder structure.

```text
train-seat-allocation-route-query/
│
├── src/
│   │
│   ├── backtracking/
│   │   ├── seat_allocation.cpp
│   │   └── seat_allocation.h
│   │
│   ├── dp/
│   │   ├── knapsack.cpp
│   │   └── knapsack.h
│   │
│   ├── graph/
│   │   ├── train_graph.cpp
│   │   └── train_graph.h
│   │
│   ├── trees/
│   │   ├── train_bst.cpp
│   │   └── train_bst.h
│   │
│   └── main.cpp
│
├── .gitignore
└── README.md
```

### Module Description

- **trees:** Contains Binary Search Tree implementation for train records.
- **graph:** Contains weighted graph representation and Dijkstra's Algorithm.
- **dp:** Contains the 0/1 Knapsack Dynamic Programming implementation.
- **backtracking:** Contains seat allocation using Backtracking.
- **main.cpp:** Serves as the main entry point and integrates all four modules.

## 7. How to Compile and Run

Make sure a C++17-compatible compiler (G++) is installed.

### Step 1: Clone the Repository

```bash
git clone https://github.com/av6938889-bit/train-seat-allocation-route-query.git
```

### Step 2: Open the Project Directory

```bash
cd train-seat-allocation-route-query
```

### Step 3: Compile the Project

```bash
g++ -std=c++17 src/main.cpp src/trees/train_bst.cpp src/graph/train_graph.cpp src/dp/knapsack.cpp src/backtracking/seat_allocation.cpp -o train_app
```

### Step 4: Run the Application

On macOS / Linux:

```bash
./train_app
```

On Windows:

```bash
train_app.exe
```

## 8. Application Menu

The application provides the following menu options:

1. Manage Train Records (BST)
2. Find Shortest Route (Dijkstra)
3. Optimize Seat Capacity (Knapsack)
4. Check Seat Allocation (Backtracking)
5. Exit

## 9. Project Limitations

- Uses simulated railway data.
- Does not connect to live railway databases.
- Does not provide real-time train tracking.
- Does not support online ticket booking or payments.
- Uses predefined sample inputs for demonstration.

## 10. Future Enhancements

- Add a graphical user interface.
- Integrate a database for train records.
- Support dynamic station and route inputs.
- Implement additional route-finding algorithms.
- Improve seat allocation with advanced optimization techniques.
- Introduce real-time railway information integration.

## 11. Conclusion

The Train Seat Allocation and Route Query Prototype demonstrates the practical use of Data Structures and Algorithms in railway management.

By combining Binary Search Trees, Graph Algorithms, Dynamic Programming and Backtracking, the project provides an understanding of algorithmic problem-solving and their applications in a real-world-inspired railway system.

## 12. Author Information

**Name:** Abhishek Verma

**Branch:** BTech CSE-A

**Institution:** Noida Institute of Engineering and Technology (NIET), Greater Noida

**Course:** Data Structures and Algorithms-II

**Course Code:** CCSE0301

## 13. GitHub Repository

**Project Source Code:**

https://github.com/av6938889-bit/train-seat-allocation-route-query

---

Developed as an academic Project-Based Learning (PBL) project at NIET Greater Noida.
