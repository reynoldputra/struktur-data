#include <iostream>
#include <iterator>
#include <list>
using namespace std;


void addEdge(list<int> adj[], int u, int v){
    if(adj[u].empty()) adj[u].push_back(u);
    if(adj[v].empty()) adj[v].push_back(v);
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void showGraph(list<int> adj[]){
    int len = sizeof(adj);
    for (int i = 0; i <= len; i++)
    {
        list<int>::iterator it;
        for(it = adj[i].begin(); it != adj[i].end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }
}


int main(){
    int v = 5;
    list<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    showGraph(adj);

}
