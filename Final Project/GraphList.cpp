#include <iostream>
#include <list>
#include <iterator>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
using namespace std;

class GraphList {
    protected:
        int v;
        vector<string> name;
        vector<list<int>> adj;
        map<pair<int,int>, int> weight;
        vector<int> dfsResult;
        int dfsWeight;
        vector<int> dijkstraRes;

    public:
        GraphList(int len) {
            v = len;
            name.assign(v+1, "");
            list<int> l;
            adj.assign(v+1, l);
            dfsResult.assign(v+1, 0);
            vector<int> vec (v+1, 0);
        }

        void addNode(int i, string r){
            name[i] = r;
        }

        void addEdge(int u, int v, int w){
            adj[u].push_back(v);
            weight.insert({make_pair(u,v), w});
            // adj[v].push_back(u); //delete this to create manual directed graph
        }

        void showGraph(){
            for (int i = 1; i <= v; i++)
            {
                list<int>::iterator it;
                cout << i << " => ";
                for (it = adj[i].begin(); it != adj[i].end(); it++)
                {
                    cout << *it << "(" << weight[make_pair(i, *it)] << ") ";
                }
                cout << endl;
            }
        }

        void DFS(int start, int end){
            cout << endl;
            cout << "## Shortest path using DFS" << endl;
            dfsWeight = INT_MAX;
            vector<int> path;
            vector<bool> visited (v+1, false);
            solveDFS(start, end, path, visited, 0 );
            
            for (int i = 0; i < dfsResult.size(); i++)
            {
                cout << dfsResult[i] << " ";
            }

            cout << endl << "Weight = " << dfsWeight << endl;
        }

        void solveDFS(int start, int end, vector<int> path, vector<bool> visited, int currWeight){
            if(start == end) {
                path.push_back(end);
                if(currWeight < dfsWeight ) {
                    dfsWeight = currWeight;
                    dfsResult = path;
                }
                
                cout << currWeight << " ";
                for (int i = 0; i < path.size(); i++)
                {
                    cout <<  path[i] << " ";
                }
                cout << endl;
            }
            
            visited[start] = true;
            path.push_back(start);
            // bool flag = false;
            list<int>::iterator it;
            for ( it = adj[start].begin(); it != adj[start].end(); it++)
            {
                if(!visited[*it]){
                    int wtemp = currWeight;
                    wtemp += weight[make_pair(start, *it)];
                    // flag = true;
                    solveDFS(*it, end, path, visited, wtemp);
                }
            }
        }

        int minDist(vector<int> dist, vector<bool> vis){
            int min = INT_MAX;
            int min_index = INT_MAX;
            for (int i = 1; i <= v; i++)
            {
                if(!vis[i] && dist[i] < min) {
                    min = dist[i];
                    min_index = i;
                }
            }

            return min_index;
        }

        void dijkstra(int start, int end){
            cout << endl << "## Dijkstra" << endl;

            vector<int> dist (v+1, INT_MAX);
            vector<bool> vis (v+1, false);
            vector<int> res (v+1, 0);

            dist[start] = 0;

            for (int itv = 1; itv <= v ; itv++)
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
                    {
                        // cout << min << " " << *it << " " << dist[min] << " " << weight[make_pair(min, *it)] << endl;
                        
                        
                        dist[*it] = dist[min] + weight[make_pair(min, *it)]; 
                        res[*it] = min;
                        for (int i = 1; i <= v; i++)
                        {
                            if(dist[i] < 10000 )
                                cout << dist[i] << " ";
                            else 
                                cout << ". ";
                        }
                        cout << endl;
                    }
                }
            }
            
            // for (int i = 1; i <= v; i++)
            // {
            //     cout << dist[i] << " ";
            // }
            // cout << endl;
            
            // for (int i = 1; i <= v; i++)
            // {
            //     cout << res[i] << " ";
            // }

            int i = res[end];
            vector<int> r;
            r.push_back(end);
            while (true)
            {
                r.push_back(i);
                if(i == start) break;
                i = res[i];
            }
            // cout << endl;

            reverse(r.begin(), r.end());

            for (int i = 0; i <  r.size(); i++)
            {
                cout << r[i] << " ";
            }
            cout << endl << "Weight = " << dist[end] << endl;
        }

        void BFS(int start, int end){
            cout << endl;
            cout << "## BFS" << endl;
            vector<int> visit (v+1, 0);
            vector<int> dist (v+1, INT_MAX);
            vector<int> domain (v+1, 0);
            queue<int> q;

            dist[start] = 0;
            q.push(start);
            visit[start] = true;

            while (!q.empty())
            {
                int curr = q.front();
                list<int>::iterator it;
                for (it = adj[curr].begin(); it != adj[curr].end(); it++)
                {

                    if(weight[make_pair(curr, *it)] + dist[curr] < dist[*it]){
                        dist[*it] = weight[make_pair(curr, *it)] + dist[curr];
                        domain[*it] = curr;
                        q.push(*it);
                        for (int i = 1; i <= v; i++)
                        {
                            if(dist[i] < 10000 )
                                cout << dist[i] << " ";
                            else 
                                cout << ". ";
                        }
                        cout << endl;
                    }
                }
                q.pop();
            }

            for (int i = 1; i <= v ; i++)
            {
                cout << domain[i] << " ";
            }
            cout << endl;
            

            vector<int> result;
            int i = end;
            while(true){
                result.push_back(i);
                if(i == start) break;
                i = domain[i];
            }

            for (int i = result.size()-1; i >= 0; i--)
            {
                cout << result[i] << " ";
            }
            
            cout << endl << "Weight = " << dist[end] << endl;
            
        }

};

int main(){
    GraphList graph1(20);

    //creating node
    graph1.addNode(1, "Rumahku");
    graph1.addNode(2, "SPBU");
    graph1.addNode(3, "Kantor_BPJS");
    graph1.addNode(4, "Masjid_Al-Kautsar");
    graph1.addNode(5, "Pengadilan_Agama"); 
    graph1.addNode(6, "Bakso_Melati"); 
    graph1.addNode(7, "RM_Nikmat_Rasa"); 
    graph1.addNode(8, "Soto_Cemara"); 
    graph1.addNode(9, "Indomaret_Veteran"); 
    graph1.addNode(10, "BNI"); 
    graph1.addNode(11, "Alun-alun"); 
    graph1.addNode(12, "Eiger_Store"); 
    graph1.addNode(13, "MR_DIY"); 
    graph1.addNode(14, "POLRES"); 
    graph1.addNode(15, "Roti_HW"); 
    graph1.addNode(16, "Pizza_Hut"); 
    graph1.addNode(17, "Galeri_Indosat"); 
    graph1.addNode(18, "Suropati_Gym"); 
    graph1.addNode(19, "Dialogi_Coffee"); 
    graph1.addNode(20, "GOR_Unsur"); 

    //creating edge
    graph1.addEdge(4 , 5 , 1 );	    graph1.addEdge(5 , 4 , 1 );
    graph1.addEdge(4 , 3 , 4 );	    graph1.addEdge(3 , 4 , 4 );
    graph1.addEdge(1 , 3 , 2 );	    graph1.addEdge(3 , 1 , 2 );
    graph1.addEdge(2 , 3 , 3 );	    graph1.addEdge(3 , 2 , 3 );
    graph1.addEdge(2 , 7 , 2 );	    graph1.addEdge(7 , 2 , 2 );
    graph1.addEdge(2 , 6 , 2 );	    graph1.addEdge(6 , 2 , 2 );
    graph1.addEdge(2 , 1 , 2 );	    graph1.addEdge(1 , 2 , 2 );
    graph1.addEdge(6 , 1 , 3 );	    graph1.addEdge(1 , 6 , 3 );
    graph1.addEdge(6 , 7 , 7 );	    graph1.addEdge(7 , 6 , 7 );
    graph1.addEdge(6 , 20, 8 );	    graph1.addEdge(20, 6 , 8 );
    graph1.addEdge(7 , 8 , 6 );	    graph1.addEdge(8 , 7 , 6 );
    graph1.addEdge(7 , 9 , 9 );	    graph1.addEdge(9 , 7 , 9 );
    graph1.addEdge(9 , 10, 3 );	    graph1.addEdge(10, 9 , 3 );
    graph1.addEdge(9 , 11, 8 );	    graph1.addEdge(11, 9 , 8 );
    graph1.addEdge(10, 11, 2 );	    graph1.addEdge(11, 10, 2 );
	graph1.addEdge(11, 12, 5 );
    graph1.addEdge(12, 13, 11);	    
    graph1.addEdge(13, 14, 4 );	    graph1.addEdge(14, 13, 4 );
    graph1.addEdge(15, 14, 1 );	    graph1.addEdge(14, 15, 1 );
    graph1.addEdge(19, 13, 10);	    graph1.addEdge(13, 19, 10);
    graph1.addEdge(19, 16, 7 );	    graph1.addEdge(16, 19, 7 );
    graph1.addEdge(19, 20, 2 );	    graph1.addEdge(20, 19, 2 );
    graph1.addEdge(18, 20, 3 );	    graph1.addEdge(20, 18, 3 );
    graph1.addEdge(13, 16, 3 );	    graph1.addEdge(16, 13, 3 );
    graph1.addEdge(17, 16, 2 );	    graph1.addEdge(16, 17, 2 );
    graph1.addEdge(17, 18, 1 );	    graph1.addEdge(18, 17, 1 );
  
    graph1.showGraph();

    int start, end;
    cin >> start >> end;

    graph1.DFS(start, end);
    graph1.dijkstra(start, end);
    graph1.BFS(start, end);
    
}