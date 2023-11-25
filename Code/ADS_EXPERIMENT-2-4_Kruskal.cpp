#include <bits/stdc++.h>
using namespace std;

class DSU { 
    int* parent; 
    int* rank; 
  
public: 
    DSU(int n) { 
        parent = new int[n]; 
        rank = new int[n]; 
  
        for (int i = 0; i < n; i++) { 
            parent[i] = -1; 
            rank[i] = 1; 
        } 
    } 
  
    // Find function 
    int find(int i) { 
        if (parent[i] == -1) 
            return i; 
  
        return parent[i] = find(parent[i]); 
    } 
  
    // Union function 
    void unite(int x, int y) { 
        int s1 = find(x); 
        int s2 = find(y); 
  
        if (s1 != s2) { 
            if (rank[s1] < rank[s2]) { 
                parent[s1] = s2; 
            } 
            else if (rank[s1] > rank[s2]) { 
                parent[s2] = s1; 
            } 
            else { 
                parent[s2] = s1; 
                rank[s1] += 1; 
            } 
        } 
    }

}; 

class Graph { 
    vector<vector<int>> edgelist; 
    int V; 
  
public: 
    Graph(int V) {
        this->V = V;
    } 
  
    // Function to add edge in a graph 
    void addEdge(int x, int y, int w) { 
        edgelist.push_back({ w, x, y }); 
    } 
  
    void kruskals_mst() { 
        // Sort all edges 
        sort(edgelist.begin(), edgelist.end()); 
  
        // Initialize the DSU 
        DSU s(V); 
        int ans = 0; 
        cout << "\nFollowing are edges in constructed MST: "<< endl; 
        for (auto edge : edgelist) { 
            int w = edge[0]; 
            int x = edge[1]; 
            int y = edge[2]; 
  
            // Take edge in MST if it does not forms a cycle 
            if (s.find(x) != s.find(y)) { 
                s.unite(x, y); 
                ans += w; 
                cout <<x<< " -- " <<y<< " == " <<w<< endl; 
            } 
        } 
        cout << "\nMinimum Cost Spanning Tree: " << ans <<endl; 
    } 

    // Print graph
    void printGraph() {
        cout << "\nThe given Graph(start_vertex, end_vertex, weight): "<<endl;
        for (auto edge : edgelist) { 
            int w = edge[0]; 
            int x = edge[1]; 
            int y = edge[2]; 
  
            cout <<x<< " -- " <<y<< " == " <<w<< endl;  
        } 
    }

}; 

int main() {
    
    cout<<"\nExperiment-2.4 (Ashish Kumar, 23MAI10008)"<<endl<<endl;
    cout<<"Constructing MST using Kruskal's Algorithm ..."<<endl;

    Graph g(4); 
    g.addEdge(0, 1, 10); 
    g.addEdge(1, 3, 15); 
    g.addEdge(2, 3, 4); 
    g.addEdge(2, 0, 6); 
    g.addEdge(0, 3, 5); 

    // Print Graph
    g.printGraph();
  
    // Function call 
    g.kruskals_mst();

    return 0;
}
