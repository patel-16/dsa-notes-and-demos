#include <vector>
#include <iostream>

using namespace std;

/* 

Problem statement

this function is supposed to return the shortest distances from source (src)

to all other nodes in a vector, thus the vector<int> return type

(assumptions - edge weights positive, connected graph ?? )

*/

// just a redundant note on how & is used for passing by reference
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

    // here V is your usual N/n (number of vertices)



}

int main() {

    cout << "Enter number of vertices and edges in format \n V E \n";
    
    int V, E;
    cin>>V>>E;

    cout <<"\n";
    cout << "Enter E edge info in format u v w \n";
    cout<< " u - src, v - dest, w - weight \n\n";

    vector<vector<int>> edges;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;

        cin>>u>>v>>w;

        edges.push_back({u, v, w});

    }

    cout<<"\n";
    cout<<"Enter source for dijkstra to get shortest path from \n";
    
    int src;
    cin>>src;

    cout << "\n\n";



    vector<int> distancesFromSrc = dijkstra(V, edges, src);
    
    for (int i = 0; i<V ; i++) {
        cout<< distancesFromSrc[i] << " ";
    }

    cout<<"\n";
    

}
