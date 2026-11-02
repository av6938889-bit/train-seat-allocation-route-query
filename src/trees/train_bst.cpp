
#include "train_bst.h"

// Node constructor
TrainBST::Node::Node(int id, string name) {
    trainID = id;
    trainName = name;
    left = right = nullptr;
}

// Constructor
TrainBST::TrainBST() {
    root = nullptr;
}

// Insert a train into BST
TrainBST::Node* TrainBST::insert(
    Node* node, int id, string name) {

    if (node == nullptr)
        return new Node(id, name);

    if (id < node->trainID)
        node->left = insert(node->left, id, name);

    else if (id > node->trainID)
        node->right = insert(node->right, id, name);

    else
        cout << "Duplicate Train ID not allowed!\n";

    return node;
}

// Search train by ID
TrainBST::Node* TrainBST::search(Node* node, int id) {
    if (node == nullptr || node->trainID == id)
        return node;

    if (id < node->trainID)
        return search(node->left, id);

    return search(node->right, id);
}

// Inorder traversal
void TrainBST::inorder(Node* node) {
    if (node == nullptr)
        return;

    inorder(node->left);

    cout << "Train ID: " << node->trainID
         << " | Train Name: " << node->trainName << endl;

    inorder(node->right);
}

// Insert train record
void TrainBST::insertTrain(int id, string name) {
    root = insert(root, id, name);
}

// Search train record
bool TrainBST::searchTrain(int id) {
    return search(root, id) != nullptr;
}

// Display all trains
void TrainBST::displayTrains() {
    if (root == nullptr) {
        cout << "No train records available!\n";
        return;
    }

    cout << "\nTrain Records (Sorted by ID):\n";
    inorder(root);
}

// Free allocated memory
void TrainBST::destroy(Node* node) {
    if (node == nullptr)
        return;

    destroy(node->left);
    destroy(node->right);
    delete node;
}

// Destructor
TrainBST::~TrainBST() {
    destroy(root);
}
