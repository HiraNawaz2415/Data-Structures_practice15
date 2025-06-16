#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void dfs(int nodeIndex, const vector<vector<int>> &adj, vector<bool> &visited, const vector<int> &nodeValues) {
    visited[nodeIndex] = true;
    cout << nodeValues[nodeIndex] << " ";

    for (int neighbor : adj[nodeIndex]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, nodeValues);
        }
    }
}

int main() {
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> nodeValues(n);
    unordered_map<int, int> valueToIndex;

    cout << "Enter " << n << " node values:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nodeValues[i];
        valueToIndex[nodeValues[i]] = i;
    }

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> adj(n);
    cout << "Enter " << e << " edges (node_value1 node_value2):\n";
    for (int i = 0; i < e; ++i) {
        int u_val, v_val;
        cin >> u_val >> v_val;
        int u = valueToIndex[u_val];
        int v = valueToIndex[v_val];
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    int startVal;
    cout << "Enter start node value for DFS: ";
    cin >> startVal;
    int startIndex = valueToIndex[startVal];

    vector<bool> visited(n, false);
    cout << "DFS Traversal: ";
    dfs(startIndex, adj, visited, nodeValues);
    cout << endl;

    return 0;
}
