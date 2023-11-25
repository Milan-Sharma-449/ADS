#include <bits/stdc++.h>
using namespace std;
 
// Number of vertices in the graph
#define V 5

void printGraph(int graph[V][V]) {
    cout<<"\nThe given Graph Adjacency Matrix: "<<endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
 
// Find the vertex with minimum key value
int minKey(int key[], bool mstSet[]) {

    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v], min_index = v;
        }
    }

    return min_index;
}
 
// Print the constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V]) {

    int ans = 0;
    cout << "\nFollowing are edges in constructed MST: "<< endl; 
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
        ans += graph[i][parent[i]];
    }
    cout << "\nMinimum Cost Spanning Tree: " << ans <<endl;

}
 
// Construct and print MST for a graph
void primMST(int graph[V][V])
{
    // Array to store constructed MST
    int parent[V];
 
    // Key values used to pick minimum weight edge in cut
    int key[V];
 
    // Set of vertices included in MST
    bool mstSet[V];
 
    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX, mstSet[i] = false;
    }

    // Always include first 1st vertex in MST.
    key[0] = 0;
    parent[0] = -1;
 
    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
         
        // Pick the minimum key vertex
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }
 
    // Print the constructed MST
    printMST(parent, graph);
} 

int main() {
    
    cout<<"\nExperiment-2.4 (Ashish Kumar, 23MAI10008)"<<endl<<endl;
    cout<<"Constructing MST using Prim's Algorithm ..."<<endl;

    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    // Print Graph
    printGraph(graph);
 
    // Print the solution
    primMST(graph);

    return 0;
}
