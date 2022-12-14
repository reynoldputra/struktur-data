#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <iterator>
using namespace std;

class Graph{
    protected:
        int v;
        vector<list<int>> adj;
        vector<int> dep;

    public:
        Graph(int len){
            v = len;
            list<int> l;
            adj.assign(v, l);
            dep.assign(v, 0);
        }   

        void addEdge(int v1, int v2){
            adj[v1].push_back(v2);
            dep[v2]++;
            
        }

        void showGraph(){
            for (int i = 0; i < v; i++)
            {
                list<int>::iterator it;
                for (it = adj[i].begin() ; it != adj[i].end(); it++)
                {
                    cout << *it << " ";
                }
                cout << endl;
            }   
        }

        void topSort(){
            queue<int> q;
            vector<bool> vis (v, false);
            vector<int> res;
            for (int i = 0; i < dep.size(); i++)
            {
                if(dep[i] == 0 ){
                    vis[i] == true;
                    q.push(i);
                }

            }

            while (!q.empty())
            {
                int curr = q.front();
                vis[curr] = true;
                cout << curr << " ";
                q.pop();
                res.push_back(curr);
                list<int>::iterator it;
                for (it = adj[curr].begin(); it != adj[curr].end(); it++)
                {
                    dep[*it]--;
                    if(dep[*it] == 0 && !vis[*it]){
                        q.push(*it);
                    }
                }
            }  
        }
};

int main(){
    // int a;
    // cin >> a;
    Graph graph1(14);
    
    graph1.addEdge(0,2);
    graph1.addEdge(0,3);
    graph1.addEdge(0,6);
    graph1.addEdge(1,4);
    graph1.addEdge(2,6);
    graph1.addEdge(3,4);
    graph1.addEdge(3,1);
    graph1.addEdge(4,5);
    graph1.addEdge(4,8);
    graph1.addEdge(6,7);
    graph1.addEdge(6,11);
    graph1.addEdge(7,4);
    graph1.addEdge(7,12);
    graph1.addEdge(9,2);
    graph1.addEdge(9,10);
    graph1.addEdge(10,6);
    graph1.addEdge(11,12);
    graph1.addEdge(12,8);
    
    // graph1.showGraph();
    graph1.topSort();
}


/*
14

*/