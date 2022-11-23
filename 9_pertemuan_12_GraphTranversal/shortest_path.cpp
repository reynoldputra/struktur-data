#include <iostream>
#include <iterator>
#include <list>
#include <queue>
using namespace std;

class Graph {
    protected:
        int v;
        list<int> adj[100];
        int res[100];

    public:
        Graph(int len) {
            v = len;
        }

        void addEdge(int u, int v){
            adj[u].push_back(v);
        }

        void showGraph(){
            cout << "===Show Graph===" << endl;
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

        void BFS(int start, int end){
            cout << "===BFS===" << endl;
            bool visited[100];
            for (int i = 0; i < v; i++)
            {
                visited[i] = false;
                res[i] = -1;
            }
            
            queue<int> q;

            visited[start] = true;

            list<int>::iterator it;

            q.push(start);

            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                for (it = adj[curr].begin(); it != adj[curr].end(); it++)
                {
                    int index = *it;
                    if(!visited[index])
                    {   
                        cout << index << " " << curr << endl;
                        res[index] = curr;
                        visited[index] = true;
                        q.push(index);
                    }
                }
            }

            int s = end;
            int resArr[100];
            int i = 0;
            while(s){
                resArr[i] = s;
                i++;
                s = res[s];
                if(s == start){
                    resArr[i] = s;
                    break;
                }
            }
            
            cout << "===Shortest Path===" << endl;

            while (i != -1)
            {
                cout << resArr[i] << " ";
                i--;
            }
            
            cout << endl;
        }
};


int main(){
    cout << "#GRAPH1" << endl;
    Graph graph1(5);

    graph1.addEdge( 4, 2);
    graph1.addEdge( 4, 3);
    graph1.addEdge( 2, 1);
    graph1.addEdge( 2, 3);
    graph1.addEdge( 1, 3);
    graph1.addEdge( 0, 1);
    
    graph1.showGraph();

    graph1.BFS(4, 1);



    cout << "#GRAPH2" << endl;
    Graph graph2(8);

    graph2.addEdge( 0, 1);
    graph2.addEdge( 0, 3);
    graph2.addEdge( 1, 2);
    graph2.addEdge( 3, 4);
    graph2.addEdge( 3, 7);
    graph2.addEdge( 4, 5);
    graph2.addEdge( 4, 6);
    graph2.addEdge( 4, 7);
    graph2.addEdge( 5, 6);
    graph2.addEdge( 6, 7);
    
    graph2.showGraph();

    graph2.BFS(0, 7);
}
