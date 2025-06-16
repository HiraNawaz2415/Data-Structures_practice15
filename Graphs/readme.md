# Graphs in Data Structures
## What is a Graph?
- A Graph is a non-linear data structure consisting of a finite set of vertices (or nodes) and a set of edges connecting them.
- It is used to represent networks such as social networks, communication networks, maps, etc.

---
## Terminology:
- **Vertex (Node):** A fundamental part of a graph where data is stored.

- **Edge (Arc):** A connection between two vertices.

- **Directed Graph (Digraph):** Edges have directions (A → B).

- **Undirected Graph:** Edges do not have direction (A — B).

- **Weighted Graph:** Each edge has a weight (or cost).

- **Unweighted Graph:** All edges are treated equally.

---
## Types of Graphs
| Type               | Description                                   |
| ------------------ | --------------------------------------------- |
| Directed Graph     | Edges have direction (u → v)                  |
| Undirected Graph   | Edges are bidirectional (u — v)               |
| Weighted Graph     | Each edge has an associated weight            |
| Unweighted Graph   | Edges do not carry any weight                 |
| Cyclic Graph       | Contains at least one cycle (loop path)       |
| Acyclic Graph      | No cycles; useful in topological sorting      |
| Connected Graph    | There’s a path between every pair of vertices |
| Disconnected Graph | Some vertices are not reachable from others   |
| Complete Graph     | Every node is connected to every other node   |

---

## What is a Dense Graph?
- A dense graph has a lot of connections between the nodes.

- Almost every node is connected to every other node.

- Think of it like a group of friends where everyone knows everyone.
**Example:**
- If there are 5 people, and each one is friends with almost all others — that's a dense graph.

---

## What is a Sparse Graph?
- A sparse graph has very few connections between the nodes.

- Most nodes are not directly connected.

- Think of it like a classroom where most students don't talk to each other.

**Example:**
- If there are 5 people, and only 2 pairs of them are friends — that's a sparse graph.

## Graph Representations
### 1. Adjacency Matrix
- 2D array of size V x V where matrix[i][j] = 1 if there is an edge from i to j.

- Good for dense graphs, but takes O(V^2) space.

### 2. Adjacency List
- An array/list of lists where each index contains a list of connected vertices.

- Good for sparse graphs; space-efficient (O(V + E)).

---
## Graph Traversal Algorithms
### **1. Breadth-First Search (BFS)**
- Explores nodes layer by layer.

- Uses a queue.

- Good for shortest path in unweighted graphs.

### **2. Depth-First Search (DFS)**
- Explores as far as possible down one branch before backtracking.

- Uses stack (or recursion).

---
## Applications of Graphs

| Domain            | Application Example                      |
| ----------------- | ---------------------------------------- |
| Maps & Navigation | GPS, route finding (Dijkstra, A\*)       |
| Networking        | Internet, routers, social networks       |
| AI & Games        | Pathfinding, state-space exploration     |
| Computer Vision   | Object detection using image graphs      |
| Compilers         | Dependency analysis, topological sorting |
| Scheduling        | Task scheduling (using DAGs)             |

---
##  Common Graph Algorithms

| Algorithm         | Purpose                        | Time Complexity |
| ----------------- | ------------------------------ | --------------- |
| BFS/DFS           | Graph traversal                | O(V + E)        |
| Dijkstra's        | Shortest path (non-negative)   | O(E + V log V)  |
| Bellman-Ford      | Shortest path (with negatives) | O(V × E)        |
| Floyd-Warshall    | All-pairs shortest path        | O(V³)           |
| Kruskal’s/Prim’s  | Minimum Spanning Tree (MST)    | O(E log V)      |
| Topological Sort  | Linear order of DAG            | O(V + E)        |
| Tarjan’s/Kosaraju | Strongly Connected Components  | O(V + E)        |

---
## Bipartite Graph
A graph is bipartite if:

- You can divide all the nodes into two groups such that
- No two nodes in the same group are connected directly by an edge.
Think of it like two teams where:
- Edges are only allowed between players of different teams.
- You can use 2 colors to color the nodes, making sure no two connected nodes have the same color.

**Example use:** Matching problems (jobs vs workers, students vs projects).

---
## Topological Sort
Topological sorting is:

- A linear order of nodes in a Directed Acyclic Graph (DAG).

- For every directed edge u → v, node u comes before v in the order.

- It’s used when tasks depend on other tasks.

- **Example:** Course prerequisite order, build systems.

---
## DAG (Directed Acyclic Graph)
A DAG is:

 - A graph where edges have direction, and
 - There are no cycles (you can't return to the same node following edge directions).

- **Example:** Task scheduling, dependency graphs, compiler optimization.

---
## Spanning Tree
A spanning tree of a graph is:

 - A subgraph that includes all the nodes,
 - Is connected (every node is reachable), andHas no cycles.
 - If a graph has n nodes, the spanning tree will have exactly n-1 edges.
 - Used to create a minimal connection between components.

---
## Minimum Spanning Tree (MST)
A minimum spanning tree is:

 - A spanning tree where the sum of all edge weights is the smallest possible.

**Algorithms:**

1. **Kruskal's Algorithm:** Sort edges, add smallest ones that don’t form a cycle.
2. **Prim's Algorithm:** Start from one node and expand by adding smallest edges.

**Example:** Building the cheapest network of roads, cables, or pipes.


---
## Sample Questions for Practice
- Detect cycle in a graph.
- Find shortest path from a source to all vertices.
- Number of connected components.
- Check if a graph is bipartite.
- Topological sort of a DAG.
- Minimum spanning tree of a graph.
