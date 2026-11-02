
#include "knapsack.h"

int Knapsack::solve(vector<int> weights,
                    vector<int> values,
                    int capacity) {

    int n = weights.size();

    vector<vector<int>> dp(
        n + 1, vector<int>(capacity + 1, 0)
    );

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {

            if (weights[i - 1] <= w) {
                dp[i][w] = max(
                    values[i - 1] +
                    dp[i - 1][w - weights[i - 1]],

                    dp[i - 1][w]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}
