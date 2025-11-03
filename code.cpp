#include <iostream>
#include <vector>
using namespace std;

// Function to print the assigned frequencies
void printSolution(const vector<int>& color) {
    cout << "Frequency assignment for each cell:\n";
    for (int i = 0; i < color.size(); i++) {
        cout << "Cell " << i + 1 << " → Frequency " << color[i] << "\n";
    }
}

// Function to check if current color assignment is valid
bool isSafe(int node, const vector<vector<int>>& graph, const vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[node][i] && color[i] == c)
            return false;
    }
    return true;
}

// Backtracking function
bool solveGraphColoring(const vector<vector<int>>& graph, int m, vector<int>& color, int node) {
    if (node == graph.size()) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(node, graph, color, c)) {
            color[node] = c;

            if (solveGraphColoring(graph, m, color, node + 1))
                return true;

            color[node] = 0; // backtrack
        }
    }

    return false;
}

int main() {
    int n;
    cout << "Enter number of cells (nodes): ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter adjacency matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int m;
    cout << "Enter number of available frequencies (colors): ";
    cin >> m;

    vector<int> color(n, 0);

    if (solveGraphColoring(graph, m, color, 0))
        printSolution(color);
    else
        cout << "No valid frequency assignment possible.\n";

    return 0;
}
