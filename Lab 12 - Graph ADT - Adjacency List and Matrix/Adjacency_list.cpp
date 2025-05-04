#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices);
    void insertEdge(int u, int v);
    void deleteEdge(int u, int v);
    void searchEdge(int u, int v);
    void displayGraph();
};

// Constructor
Graph::Graph(int vertices) {
    V = vertices;
    adj.resize(V);
}

// Insert an edge
void Graph::insertEdge(int u, int v) {
    if (u >= V || v >= V) {
        cout << "Invalid vertices!\n";
        return;
    }
    adj[u].push_back(v);
    adj[v].push_back(u); // Undirected graph
    cout << "Edge inserted.\n";
}

// Delete an edge
void Graph::deleteEdge(int u, int v) {
    adj[u].erase(remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
    adj[v].erase(remove(adj[v].begin(), adj[v].end(), u), adj[v].end());
    cout << "Edge deleted.\n";
}

// Search for an edge
void Graph::searchEdge(int u, int v) {
    if (find(adj[u].begin(), adj[u].end(), v) != adj[u].end()) {
        cout << "Edge exists between " << u << " and " << v << ".\n";
    } else {
        cout << "Edge does not exist.\n";
    }
}

// Display the graph
void Graph::displayGraph() {
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

// Main menu
int main() {
    int V, choice, u, v;
    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter two vertices (u v): ";
                cin >> u >> v;
                g.insertEdge(u, v);
                break;
            case 2:
                cout << "Enter two vertices (u v): ";
                cin >> u >> v;
                g.deleteEdge(u, v);
                break;
            case 3:
                cout << "Enter two vertices (u v): ";
                cin >> u >> v;
                g.searchEdge(u, v);
                break;
            case 4:
                g.displayGraph();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
