
#include <iostream>
using namespace std;

int main() {
    int cost[4][4] = {
        {0, 10, 6, 5},
        {10, 0, 999, 15},
        {6, 999, 0, 4},
        {5, 15, 4, 0}
    };

    int visited[4] = {1, 0, 0, 0};
    int edges = 0, total = 0;

    cout << "Roads selected:\n";

    while (edges < 3) {
        int min = 999, u = -1, v = -1;

        for (int i = 0; i < 4; i++) {
            if (visited[i]) {
                for (int j = 0; j < 4; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        cout << u + 1 << " - " << v + 1
             << " : " << min << endl;

        visited[v] = 1;
        total += min;
        edges++;
    }

    cout << "Minimum cost = " << total;

    return 0;
}
