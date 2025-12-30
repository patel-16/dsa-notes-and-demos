#include <vector>
#include <iostream>

using namespace std;

/* 

Problem statement

this function is supposed to return the shortest distances from source (src)

to all other nodes in a vector, thus the vector<int> return type

(assumptions - edge weights positive, connected graph 

//  
later we'll try to see variations where these assumptions don't hold true
)

*/

// just a redundant note on how & is used for passing by reference
// TODO - ADD TIME COMPLEXITY ANALYSIS !!!! V. IMP
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

    // here V is your usual N/n (number of vertices)

    // now point one - since we need to return shortest distances from src let's pick
    // up the min weight edge (src TO min1) from src as the first step. (this definitely will be part of answer, for src to the other end of this edge)
    // (i.e. any path will go through one of the neighbors of src say N(src), and if any other is taken for min1, it won't be optimal)

    // point 2 - if we go sort of level by level, then we can always pick the node with minimum distance as mentioned above..
    // we picked the minimum dist guy from N(src) in point 1, now we can look in N(min1) + N(src) (either direct from src or via min1) 

    // as can be guessed, it is a sophisticated greedy algo...

    vector<int> distances(V, INT_MAX);

    // just to be clear 0,1,2....,V-1
    distances[src] = 0;

    vector<vector<vector<int>>> adjacency_list(V);
    
    for (int i = 0; i < edges.size(); i++)
    {
        adjacency_list[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adjacency_list[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    // sort of visited array for nodes whose distances are finalized
    vector<bool> dist_finalized(V, false);

    // TODO - check the syntax properly and try to see what's the logic behind this 
    // weird structure...comparator etc.
    // this is supposed to be a min heap
    priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > pq_dist_node;

    // earlier instead of priority queue for a slightly inefficient approach, just loop through and find the minimum
    // TODO - maybe check this on gfg or self later.

    pq_dist_node.push({0, src});

    while (! pq_dist_node.empty())
    {
        vector<int> topEntry = pq_dist_node.top();
        pq_dist_node.pop();
        int currentNode = topEntry[1];

        // N0 - check the N0 below...we handle multiple entries here...
        // (not for correctness, but for clearing the clutter in the priority queue
        // as the while loop depends on it)
        if (dist_finalized [ currentNode ]) {
            continue;
        }

        dist_finalized [ currentNode ] = true;
        distances [ currentNode ] = topEntry[0];

        for (int i = 0; i < adjacency_list[currentNode].size(); i++)
        {
            vector<int> edge = adjacency_list[currentNode][i];

            // edge [0] - node, edge [1] - weight

            if (dist_finalized [edge[0]]) {
                continue;
            }
            
            distances [ edge[0] ] = min( distances[ edge[0] ], distances[ currentNode ] + edge[1] );

            // N0 - see here...this push can lead to multiple entries for the same vertex
            pq_dist_node.push({distances[ edge[0] ], edge[0]});

            
        }
        
    }


    return distances;

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
