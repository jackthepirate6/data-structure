// C++ program to print DFS traversal from
// a given vertex in a  given graph
#include<iostream>
#include<list>
using namespace std;
 
// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    int ip;
    int *fv;
    // Pointer to an array containing
    // adjacency lists
    list<int> *adj;
 
    // A recursive function used by DFS
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);   // Constructor
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
    
    void toposort();
};
 
Graph::Graph(int V)
{
    this->V = V;
    fv = new int[V];
    this->ip = V-1;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to vb
