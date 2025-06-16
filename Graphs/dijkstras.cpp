#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(int startIndex, const vector<vector<pii>> &adj, const vector<int> &nodeValues) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    dist[startIndex] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, startIndex});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto &[v, weight] : adj[u]) {
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from " << nodeValues[startIndex] << ":\n";
    for (int i = 0; i < n; ++i)
        cout << "To " << nodeValues[i] << " = " << dist[i] << endl;
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
        adj[v].emplace_back(u, w); // undirected
    }

    int startVal;
    cout << "Enter start node value for Dijkstra: ";
    cin >> startVal;
    int startIndex = valueToIndex[startVal];

    dijkstra(startIndex, adj, nodeValues);
    return 0;
}
