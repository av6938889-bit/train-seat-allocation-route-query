#ifndef TRAIN_BST_H
#define TRAIN_BST_H

#include <iostream>
#include <string>
using namespace std;

class TrainBST {
private:
    struct Node {
        int trainID;
        string trainName;
        Node* left;
        Node* right;

        Node(int id, string name);
    };

    Node* root;

    Node* insert(Node* node, int id, string name);
    Node* search(Node* node, int id);
    void inorder(Node* node);
    void destroy(Node* node);

public:
    TrainBST();
    ~TrainBST();

    void insertTrain(int id, string name);
    bool searchTrain(int id);
    void displayTrains();
};

#endif
