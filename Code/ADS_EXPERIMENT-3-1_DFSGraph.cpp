#include <bits/stdc++.h>
using namespace std;

class Graph {

	// Number of vertices
	int V;
	
    // Pointer to an array containing adjacency lists
	vector< vector<int> > adj;
    vector<bool> visited;
    
public:
	// Constructor
	Graph(int V) {
        this->V = V;
        adj.resize(V);
        visited.resize(V,false);
    }

	// Function to add an edge to graph
	void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

	// Prints BFS traversal of graph fromv source s
	void DFS(int s) {

        // Mark the current node as visited and print it
        visited[s] = true;
        cout << s << " ";

        // Recur for all the vertices adjacent to this vertex
        vector<int>::iterator i;
        for (i = adj[s].begin(); i != adj[s].end(); i++) {
            if (!visited[*i]) {
                DFS(*i);
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
    cout<<"Performing DFS Traversal of Graph ..."<<endl;

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
	cout << "\nDepth First Traversal (starting from vertex 2): \n";
	g.DFS(2);
	return 0;
}