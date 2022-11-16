#include <iostream>
#include <iterator>
#include <list>
#include <queue>
using namespace std;

class Graph {
    protected:
        int v;
        list<int> adj[100];

    public:
        Graph(int len) {
            v = len;
        }

        void addEdge(int u, int v){
            adj[u].push_back(v);
        }

        void showGraph(){
            for (int i = 0; i < v; i++)
            {
                list<int>::iterator it;
                cout << i << " ";
                for(it = adj[i].begin(); it != adj[i].end(); ++it){
                    cout << *it << " ";
                }
                cout << endl;
            }
        }

        void BFS(int start){
            cout << "===BFS===" << endl;
            bool visited[100];
            for (int i = 0; i < v; i++)
            {
                visited[i] = false;
            }
            
            queue<int> q;

            visited[start] = true;

            list<int>::iterator it;

            q.push(start);

            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                cout << "(V" << curr << ")" << endl;
                for (it = adj[curr].begin(); it != adj[curr].end(); it++)
                {
                    int index = *it;
                    if(!visited[index])
                    {
                        visited[index] = true;
                        q.push(index);
                    }
                }
            }
        }
};


int main(){
    Graph graph1(5);

    graph1.addEdge( 4, 2);
    graph1.addEdge( 4, 3);
    graph1.addEdge( 2, 1);
    graph1.addEdge( 2, 3);
    graph1.addEdge( 1, 3);
    graph1.addEdge( 0, 1);
    
    graph1.showGraph();

    graph1.BFS(4);
}
