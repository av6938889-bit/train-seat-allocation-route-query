
#include <iostream>
#include <vector>
#include <limits>
#include "trees/train_bst.h"
#include "graph/train_graph.h"
#include "dp/knapsack.h"
#include "backtracking/seat_allocation.h"

using namespace std;

int main() {
    TrainBST bst;
    TrainGraph graph(4);
    Knapsack kp;
    SeatAllocator allocator;

    int choice;

    // Sample railway routes
    graph.addRoute(0, 1, 12);
    graph.addRoute(1, 2, 18);
    graph.addRoute(0, 2, 35);
    graph.addRoute(2, 3, 8);

    do {
        cout << "\n===== TRAIN SEAT ALLOCATION AND ROUTE QUERY =====\n";
        cout << "1. Manage Train Records (BST)\n";
        cout << "2. Find Shortest Route (Dijkstra)\n";
        cout << "3. Optimize Seat Capacity (Knapsack)\n";
        cout << "4. Check Seat Allocation (Backtracking)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!\n";
            continue;
        }

        switch (choice) {
            case 1: {
                int id;
                string name;

                cout << "Enter Train ID: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter Train Name: ";
                getline(cin, name);

                bst.insertTrain(id, name);
                bst.displayTrains();
                break;
            }

            case 2:
                graph.dijkstra(0);
                break;

            case 3: {
                vector<int> weights = {10, 20, 30};
                vector<int> values = {60, 100, 120};

                cout << "Maximum value: "
                     << kp.solve(weights, values, 50) << endl;
                break;
            }

            case 4: {
                vector<int> seats = {10, 20, 15, 5};
                int required = 25;

                if (allocator.canAllocate(seats, required))
                    cout << "Seat allocation is possible.\n";
                else
                    cout << "Seat allocation is not possible.\n";
                break;
            }

            case 5:
                cout << "Exiting application...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
