
/*
 * C++ Program to Implement Adjacency List Graph Implementationn UNDIRECTED
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
 
/*
 * Adjacency List Node
 */ 
struct AdjListNode
{
    int data;
    int weight;
    struct AdjListNode* next;
};
 
/*
 * Adjacency List
 */  
struct AdjList
{
    struct AdjListNode *head;
};
 
int explored[5] = {0};
int wt[5] = {0};

/*
 * Class Graph
 */ 
class Graph
{
    public:
        int V;
        AdjList* array; 
        Graph(int V)
        {
            this->V = V;
            array = new AdjList [V];		 
            for (int i = 0; i < V; ++i)
                array[i].head = NULL;
            int wt[V] = {0};  		
        }

        
        void addEdge(int src, int dest, int weight)
        {	
        								
            AdjListNode* newNode = new AdjListNode; 
            newNode->data = dest;			
            newNode->next = NULL;        							
            newNode->next = array[src].head;
            newNode->weight = weight;
            array[src].head = newNode;		
            
		
	    newNode = new AdjListNode; 		
            newNode->data = src;				
            newNode->next = NULL;		
            newNode->next = array[dest].head;
            newNode->weight = weight;	
            array[dest].head = newNode;		
        }
         
        void printGraph()
        {
            int v;
            for (v = 0; v < V; ++v)
            {
                AdjListNode* tmp = array[v].head;		 
                cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
                while (tmp)
                {
                    cout<<"-> "<<tmp->data;
                    tmp = tmp->next;
                }
                cout<<endl;
            }
        }

	void djik()
        {
        	vector<int> expl_n;
                expl_n.push_back(0);
                explored[0] = 1;
                int count = 4;
                while(count > 0)
                {
                	vector<int>::iterator ptr;
                        int min=90,min_nd;
                        for (ptr = expl_n.begin(); ptr < expl_n.end(); ptr++)
                        {
                     		AdjListNode* next = array[*ptr].head;
                                while(next)
                                {
                                      if(explored[next->data]==1)
                                      {
                                      next = next->next;
                                      continue; 
                                      }   
                          
                                      if( wt[*ptr] + next->weight < min )
                                      {
                                       min = wt[*ptr] + next->weight;
                                       min_nd = next->data;
                                      }
                                      next = next->next;
                                } 	
                        }
                        count--;
                        expl_n.push_back(min_nd); 
                        wt[min_nd] = min;
                        explored[min_nd] = 1;  
                        cout<<"this node is explored "<<min_nd<<" hte wt is "<<wt[min_nd]<<endl;
                }	      	
        		   
        }
};



int main()
{
    Graph gh(5);
    gh.addEdge(0, 1, 5);
    gh.addEdge(0, 4, 3);
    gh.addEdge(1, 2, 6);
    gh.addEdge(1, 3, 7);
    gh.addEdge(1, 4, 2);
    gh.addEdge(2, 3, 3);
    gh.addEdge(3, 4, 7);

    cout<<gh.array[1].head->data<<endl; 
    gh.djik();
    return 0;
}

