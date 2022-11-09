#include <iostream>
using namespace std;

int init(int **arr, int v, int m){
    for (int i = 0; i < v ; i++)
    {
        arr[i] = (int *) malloc(v * sizeof(int));
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = 0;
        }   
    }
}

int main(){
    int v, m;
    cin >> v >> m;
    int **arr;
    arr = (int **) malloc(m * sizeof(int*));
    init(arr, v, m);

    
    int x, y;
    while(true){
        cin >> x;
        if (x == -1) break;
        cin >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
}

/*
5 5
0 1
0 4
1 2
1 3
1 3
2 3
3 4
-1
*/