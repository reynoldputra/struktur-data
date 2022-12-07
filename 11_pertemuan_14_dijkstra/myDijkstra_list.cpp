#include <iostream>
#include <list>
#include <iterator>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <limits.h>
using namespace std;

class GraphList {
    protected:
        int v;
        vector<list<int>> adj;
        vector<int> res;
        map<pair<int,int>, int> weight;
    
    public: 
        GraphList(int len) {
            v = len;
            list<int> l;
            adj.assign(v, l);
            res.assign(v, 0);
        }

        void addEdge(int u, int v, int w){
            adj[u].push_back(v);
            adj[v].push_back(u);
            weight.insert({make_pair(u,v), w});
            weight.insert({make_pair(v,u), w});
        }

        void showGraph(){
            cout << "===Show Graph===" << endl;
            vector<list<int>>::iterator itv;
            int i = 0;
            for (itv = adj.begin(); itv != adj.end(); itv++)
            {
                list<int>::iterator it;
                cout << i << " => ";
                for(it = (*itv).begin(); it != (*itv).end(); ++it){
                    cout << *it << " ";
                }
                cout << endl;
                i++;
            }
        } 

        int minDist(vector<int> dist, vector<bool> vis){
            int min = INT_MAX;
            int min_index = INT_MAX;
            for (int i = 0; i < v; i++)
            {
                if(!vis[i] && dist[i] < min) {
                    min = dist[i];
                    min_index = i;
                }
            }

            return min_index;
        }

        void dijkstra(int start, int end){
        cout << "==Dijkstra==" << endl;

            vector<int> dist (v, INT_MAX);
            vector<bool> vis (v, false);

            dist[start] = 0;

            vector<list<int>>::iterator itv;
            for (itv = adj.begin(); itv != adj.end(); itv++)
            {
                int min = minDist(dist, vis);
                vis[min] = true;
                list<int>::iterator it;
                for(it = adj[min].begin(); it != adj[min].end(); ++it){
                    if (
                        weight[make_pair(min, *it)] &&
                        !vis[*it] && 
                        dist[min] + weight[make_pair(min, *it)]  < dist[*it]
                    )
                    {cout << min << " " << *it << " " << dist[min] << " " << weight[make_pair(min, *it)] << endl;
                        dist[*it] = dist[min] + weight[make_pair(min, *it)]; 
                        res[*it] = min;
                    }
                }
            }
            
            for (int i = 0; i < v; i++)
            {
                cout << dist[i] << " ";
            }
            cout << endl;
            
            for (int i = 0; i < v; i++)
            {
                cout << res[i] << " ";
            }

            int i = res[end];
            vector<int> r;
            r.push_back(end);
            while (true)
            {
                r.push_back(i);
                if(i == start) break;
                i = res[i];
            }
            cout << endl;

            reverse(r.begin(), r.end());

            for (int i = 0; i <  r.size(); i++)
            {
                cout << r[i] << " ";
            }
            
        }
};

int main(){
    GraphList graph1(9);
    graph1.addEdge(0,1,4 );
    graph1.addEdge(0,7,8 );
    graph1.addEdge(1,7,11);
    graph1.addEdge(1,2,8 );
    graph1.addEdge(7,6,1 );
    graph1.addEdge(7,8,7 );
    graph1.addEdge(6,8,6 );
    graph1.addEdge(2,8,2 );
    graph1.addEdge(2,5,4 );
    graph1.addEdge(6,5,2 );
    graph1.addEdge(2,3,7 );
    graph1.addEdge(3,5,14);
    graph1.addEdge(3,4,9 );
    graph1.addEdge(5,4,10);
  
    graph1.showGraph();

    graph1.dijkstra(0, 4);
}