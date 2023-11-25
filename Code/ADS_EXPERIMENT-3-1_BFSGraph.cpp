#include <bits/stdc++.h>
using namespace std;

class Graph {

	// Number of vertices
	int V;
	
    // Pointer to an array containing adjacency lists
	vector< vector<int> > adj;

public:
	// Constructor
	Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

	// Function to add an edge to graph
	void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

	// Prints BFS traversal of graph fromv source s
	void BFS(int s) {

        // Mark all the vertices as not visited
        vector<bool> visited(V, false);
        
        // Create a queue for BFS
	    list<int> queue;

        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue.push_back(s);

        while (!queue.empty()) {
            // Dequeue a vertex from queue and print it
            s = queue.front();
            cout << s << " ";
            queue.pop_front();

            // Get all adjacent vertices of the dequeued vertex s.
            for (auto adjacent : adj[s]) {
                // If an adjacent has not been visited, then mark it visited and enqueue it
                if (!visited[adjacent]) {
                    visited[adjacent] = true;
                    queue.push_back(adjacent);
                }
            }
        }

    }

    // Print graph
    void printGraph() {
        cout << "\nThe given Graph(start_vertex, end_vertex): "<<endl;
        for (int i = 0; i < adj.size(); i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                cout<<i<<" "<<adj[i][j]<<"\n"; 
            }
        } 
    }

};

int main() {

    cout<<"\nExperiment-3.1 (Ashish Kumar, 23MAI10008)"<<endl<<endl;
    cout<<"Performing BFS Traversal of Graph ..."<<endl;

	// Create a Graph
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

    // Print Graph
    g.printGraph();

    //Function Call
	cout << "\nBreadth First Traversal (starting from vertex 2): \n";
	g.BFS(2);
	return 0;
}