#include <iostream>
#include <iterator>
#include <queue>
using namespace std;

class GraphArray {
    protected:
        int v;
        string name[100];
        int arr[100][100];
        int res[100];
    
    public:
        GraphArray(int len){
            v = len;
            for (int i = 0; i <= v; i++)
            {
                for (int j = 0; j <= v; j++)
                {
                    arr[i][j] = 0;
                }
            }
        }
        
        void addNode(int i, string str){
            name[i] = str;
        }
        
        void addEdge(int v1, int v2){
            arr[v1][v2] = 1;
            // arr[v2][v1] = 1; //delete this to create manual directed graph
        }

        void showGraph(){
            cout << "===Show Graph===" << endl;
            cout << "    ";
            for (int k = 0; k <= v; k++)
            {
                cout << k << " ";
                if(k<10) cout << " ";
            }

            cout << endl;
            
            for (int i = 0; i <= v; i++){
                cout << i << "  ";
                if(i<10) cout << " ";
                for (int j = 0; j <= v; j++)
                {
                    cout << arr[i][j] << "  ";
                }
                cout << endl;
            }
        }

        void BFS(int start){
            cout << "===BFS===" << endl;
            bool visited[100];
            queue<int> q;

            for (int i = 0; i <= v; i++)
            {
                visited[i] = false;
            }

            visited[start] = true;
            int i;
            q.push(start);
            cout << start << endl;
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                for (int i = 0; i <= v; i++)
                {
                    if(!visited[i] && arr[curr][i] == 1){
                        cout << i << "\t <= \t" << curr << endl;
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
        }

        void BFStoEnd(int start, int end){
            cout << "===BFS to End===" << endl;
            bool visited[100];
            for (int i = 0; i <= v; i++)
            {
                visited[i] = false;
            }

            queue<int> q;
            visited[start] = true;
            int i;

            q.push(start);
            cout << start << endl;
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                for (int i = 0; i <= v; i++)
                {
                    if(!visited[i] && arr[curr][i] == 1){
                        cout << i << "\t <= \t" << curr << endl;
                        visited[i] = true;
                        q.push(i);
                        if(i == end) {
                            return;
                        }
                    }
                }
            }
        }

        void ShortestPath(int start, int end){
            cout << "===Shortest Path===" << endl;
            bool visited[100];
            for (int j = 0; j < v; j++)
            {
                visited[j] = false;
            }

            queue<int> q;
            visited[start] = true;

            q.push(start);
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                for (int i = 0; i <= v; i++)
                {
                    if(!visited[i] && arr[curr][i] == 1){
                        res[i] = curr;
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }

            
            int s = end;
            int resArr[100];
            int k = 0;
            while(s){
                resArr[k] = s;
                k++;
                s = res[s];
                if(s == start){
                    resArr[k] = s;
                    break;
                }
            }
            
            while (true)
            {
                cout << name[resArr[k]] << " ";
                if(resArr[k] == end) break;
                k--;
            }
            
            cout << endl;
        }
};

int main() {
    GraphArray graph1(20);

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

    graph1.addEdge(4, 5);	    graph1.addEdge(5, 4);
    graph1.addEdge(4, 3);	    graph1.addEdge(3, 4);
    graph1.addEdge(1, 3);	    graph1.addEdge(3, 1);
    graph1.addEdge(2, 3);	    graph1.addEdge(3, 2);
    graph1.addEdge(2, 7);	    graph1.addEdge(7, 2);
    graph1.addEdge(2, 6);	    graph1.addEdge(6, 2);
    graph1.addEdge(2, 1);	    graph1.addEdge(1, 2);
    graph1.addEdge(6, 1);	    graph1.addEdge(1, 6);
    graph1.addEdge(6, 7);	    graph1.addEdge(7, 6);
    graph1.addEdge(6, 20);	    graph1.addEdge(20, 6);
    graph1.addEdge(7, 8);	    graph1.addEdge(8, 7);
    graph1.addEdge(7, 9);	    graph1.addEdge(9, 7);
    graph1.addEdge(9, 10);	    graph1.addEdge(10, 9);
    graph1.addEdge(9, 11);	    graph1.addEdge(11, 9);
    graph1.addEdge(10, 11);	    graph1.addEdge(11, 10);
	graph1.addEdge(11, 12);
    graph1.addEdge(12, 13);	    
    graph1.addEdge(13, 14);	    graph1.addEdge(14, 13);
    graph1.addEdge(15, 14);	    graph1.addEdge(14, 15);
    graph1.addEdge(19, 13);	    graph1.addEdge(13, 19);
    graph1.addEdge(19, 16);	    graph1.addEdge(16, 19);
    graph1.addEdge(19, 20);	    graph1.addEdge(20, 19);
    graph1.addEdge(18, 20);	    graph1.addEdge(20, 18);
    graph1.addEdge(13, 16);	    graph1.addEdge(16, 13);
    graph1.addEdge(17, 16);	    graph1.addEdge(16, 17);
    graph1.addEdge(17, 18);	    graph1.addEdge(18, 17);
  
    graph1.showGraph();

    graph1.BFS(1);
    graph1.BFStoEnd(1, 13);
    graph1.ShortestPath(1, 13);
}