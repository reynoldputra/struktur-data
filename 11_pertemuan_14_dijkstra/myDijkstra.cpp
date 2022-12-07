#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

class GraphArray {
    protected:
        int v;
        vector <vector<int>> arr;
        vector <int> res;
    
    public:
        GraphArray(int len){
            v = len;
            vector<int> vec;
            vec.assign(v+1, 0);
            arr.assign(v+1, vec);
            res.assign(v+1, 0);
        }
        
        
        void addEdge(int v1, int v2, int w){
            arr[v1][v2] = w;
            arr[v2][v1] = w;
        }

        void showGraph(){
            cout << "===Show Graph===" << endl;
            cout << "    ";
            for (int k = 0; k <= v; k++)
            {
                cout << k << "  ";
                if(k<10) cout << " ";
            }

            cout << endl;
            
            for (int i = 0; i <= v; i++){
                cout << i << "  ";
                if(i<10) cout << " ";
                for (int j = 0; j <= v; j++)
                {
                    cout << arr[i][j] << "  ";
                    if(arr[i][j]<10) cout << " ";
                }
                cout << endl;
            }
        }

        int minDist(vector<int> dist, vector<bool> vis){
            int min = INT_MAX;
            int min_index = INT_MAX;
            for (int i = 0; i <= v; i++)
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
            vector<int> dist (v+1, INT_MAX);
            vector<bool> vis (v+1, false);

            dist[start] = 0;

            for (int i = 0; i <= v; i++)
            {
                int min = minDist(dist, vis);
                vis[min] = true;

                for (int j = 0; j <= v; j++)
                {
                    if (
                        min != j &&
                        arr[min][j] &&
                        !vis[j] && 
                        dist[min] + arr[min][j] < dist[j]
                    )
                    {
                        dist[j] = dist[min] + arr[min][j]; 
                        res[j] = min;
                    }
                }
            }
            
            for (int i = 0; i <= v; i++)
            {
                cout << dist[i] << " ";
            }
            cout << endl;
            
            for (int i = 0; i <= v; i++)
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

int main() {
    GraphArray graph1(8);
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