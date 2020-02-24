/*
    This file contains an implementation of Dijkstra's shortest path algorithm.
    Wikipedia definition:

        'Dijkstra's algorithm (or Dijkstra's Shortest Path First algorithm, SPF algorithm)
        is an algorithm for finding the shortest paths between nodes in a graph, which may
        represent, for example, road networks. It was conceived by computer scientist
        Edsger W. Dijkstra in 1956 and published three years later.'


    Given a specific source node, found the shortest path between this source node
    to an given ending node.
    This algorithm implements the priority queue method to optimizing.
    Will be used an adjacency list to represents the graph.

*/

#include <iostream>
#include <list>
#include <queue>

#define INFINITY 999999;

using namespace std;



class Graph{
private:
  int n; // number of nodes

  // pointer to an array that contais the adjacency lists
  list<pair<int, int>> *adj;

public:
  //constructor
  Graph(int n){
    this->n = n;

    // creates a list (size n) to store the pairs, which
    // are the tuples that hold the tarket vertex and the cost;*/
    adj = new list<pair<int, int>> [n];
  }

  // adds an edge on the graph from v1 to v2
  void addEdge(int v1, int v2, int cost){
    adj[v1].push_back(make_pair(v2, cost));
  }

  // initializes the path distance and visited vectors
  void init(int n, int source, int dist[], int visited[]){
    for(int i=0;i<n;i++){
      dist[i] = INFINITY;
      visited[i] = false;
    }
    dist[source] = 0;
  }


  // Dijkstra's algorithm
  int dijkstra(int source, int dest){
    // path distance vector
    int dist[n];

    // the vector visited is used if the vertex
    // has already been visited
    int visited[n];

    // priority queue of pair (distance, vertex)
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;


    // initialize
    init(n, source, dist, visited);

    //insert in the queue
    pq.push(make_pair(dist[source], source));

    while(!pq.empty()){
      pair<int, int> p = pq.top(); // extracts the top pairs
      int u = p.second; // takes the pair's vertex
      pq.pop();// removes from the queue

      // check if the vertex has not been expanded
      if(visited[u] == false){
        // marks as not visited
        visited[u] = true;

        for(list<pair<int, int>>::iterator it = adj[u].begin();it != adj[u].end();it++){
          // takes the adjacent vertex and the edge cost
          int vertex = it->first;
          int edge_cost = it->second;

          // (u, v) relaxing
          if(dist[vertex] > (dist[u] + edge_cost)){
            // update the distance of 'vertex' and insert in the queue
            dist[vertex] = dist[u] + edge_cost;
            pq.push(make_pair(dist[vertex], vertex));
          }
        }
      }
    }
    // returns the shortest distance to the destination
    return dist[dest];
  }
};



int main(){

  Graph g(5);

  g.addEdge(0, 1, 4);
  g.addEdge(0, 2, 2);
  g.addEdge(0, 3, 5);
  g.addEdge(1, 4, 1);
  g.addEdge(2, 1, 1);
  g.addEdge(2, 3, 2);
  g.addEdge(2, 4, 1);
  g.addEdge(3, 4, 1);

  cout << g.dijkstra(0, 4) << endl;

  return 0;

}
