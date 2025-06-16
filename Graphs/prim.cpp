#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

void primMST(int startIndex, const vector<vector<pii>> &adj, const vector<int> &nodeValues) {
    int n = adj.size();
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);

    key[startIndex] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, startIndex});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for (auto &[v, weight] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (int i = 0; i < n; ++i) {
        if (parent[i] != -1)
            cout << nodeValues[parent[i]] << " - " << nodeValues[i] << endl;
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
    vector<vector<pii>> adj(n);
    cout << "Enter " << e << " edges (node1 node2 weight):\n";
    for (int i = 0; i < e; ++i) {
        int uVal, vVal, w;
        cin >> uVal >> vVal >> w;
        int u = valueToIndex[uVal], v = valueToIndex[vVal];
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int startVal;
    cout << "Enter start node value for Prim's Algorithm: ";
    cin >> startVal;
    int startIndex = valueToIndex[startVal];

    primMST(startIndex, adj, nodeValues);
    return 0;
}
