#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool dfsCycle(int node, int parent, const vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfsCycle(neighbor, node, adj, visited))
                return true;
        } else if (neighbor != parent) {
            // A back edge found
            return true;
        }
    }

    return false;
}

bool hasCycle(const vector<vector<int>> &adj, int n) {
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (dfsCycle(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}

int main() {
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> nodeValues(n);
    unordered_map<int, int> valueToIndex;
    cout << "Enter " << n << " unique node values:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nodeValues[i];
        valueToIndex[nodeValues[i]] = i;
    }

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> adj(n);
    cout << "Enter " << e << " edges (node1 node2):\n";
    for (int i = 0; i < e; ++i) {
        int uVal, vVal;
        cin >> uVal >> vVal;
        int u = valueToIndex[uVal];
        int v = valueToIndex[vVal];
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    if (hasCycle(adj, n))
        cout << "Cycle detected in the graph.\n";
    else
        cout << "No cycle detected in the graph.\n";

    return 0;
}
