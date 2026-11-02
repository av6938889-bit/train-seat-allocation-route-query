
#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <iostream>
#include <vector>
using namespace std;

class Knapsack {
public:
    int solve(vector<int> weights,
              vector<int> values,
              int capacity);
};

#endif
