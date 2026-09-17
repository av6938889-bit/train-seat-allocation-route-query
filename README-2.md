# Train Seat Allocation and Route Query Prototype

## DSA-II PBL Project

This project demonstrates the application of Data Structures and Algorithms to a **Train Seat Allocation and Route Query Prototype**.

The prototype conceptually manages passenger records, train seats, booking priorities, stations, and route connections. The implementation uses concepts from **Unit 1 (Trees)** and **Unit 2 (Graphs)** identified in the PBL report.

## DSA Concepts Used

### Unit 1 – Trees

### 1. Binary Search Tree (BST)
Passenger records are organized using passenger IDs in a Binary Search Tree. BST supports ordered storage and searching of passenger records.

### 2. AVL Tree
An AVL Tree is used to maintain balanced passenger records and support efficient searching.

### 3. Heap / Max Heap
A Max Heap is used to process booking requests according to priority. Requests with higher priority are processed first.

### 4. Tree Traversal
Tree traversal is used to systematically process and display passenger information stored in tree structures.

## Unit 2 – Graphs

### 5. Graph
A graph represents relationships between railway stations and train routes.

### 6. Adjacency Matrix
An adjacency matrix stores direct connections between railway stations using a matrix representation.

### 7. Adjacency List
An adjacency list stores the connected stations for each station and provides another representation of the railway route graph.

## Project Features

- Passenger record management
- Passenger searching using BST
- Balanced passenger record organization using AVL Tree
- Booking priority processing using Max Heap
- Train seat allocation
- Tree traversal
- Railway station and route representation using Graph
- Adjacency Matrix representation
- Adjacency List representation
- Direct route query between stations

## Technologies Used

- C++
- Data Structures and Algorithms

## Project Structure

```text
train-seat-allocation-route-query/
│
├── main.cpp
└── README.md
```

## How the Prototype Works

1. Passenger records are inserted into a Binary Search Tree.
2. A passenger ID can be searched using the BST.
3. Passenger records are also inserted into an AVL Tree to demonstrate balanced tree organization.
4. Booking requests are inserted into a Max Heap according to their priority.
5. Available train seats are allocated to the highest-priority booking requests first.
6. Railway stations are represented as vertices of a graph.
7. Connections between stations are represented using an Adjacency Matrix and an Adjacency List.
8. A route query checks whether a direct connection exists between two stations.

## Sample Stations

The prototype uses sample railway stations such as:

- Delhi
- Kanpur
- Lucknow
- Prayagraj
- Varanasi

## Compilation and Execution

Compile using:

```bash
g++ -std=c++17 main.cpp -o train
```

Run using:

```bash
./train
```

## Project Scope

This is a prototype implementation based on the DSA-II concepts identified in the PBL report. Unit 2 is limited to graph representation using an Adjacency Matrix and Adjacency List; shortest-path algorithms are not included.

## PBL Project

**Project Title:** Train Seat Allocation and Route Query Prototype  
**Course:** Data Structure and Algorithms – II  
**Course Code:** CCSE0301  
**Student:** Abhishek Verma
