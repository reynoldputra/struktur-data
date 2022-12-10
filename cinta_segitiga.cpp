#include <iostream>
using namespace std;


int main(){
    int N;
    bool res = false;
    cin >> N;
    int N2 = N;
    int arr[10000];
    N++;
    int i = 1;
    while (N--)
    {
        int t;
        cin >> t;
        arr[i] = t;
        i++;
    }

    for (int i = 1; i <= N2; i++)
    {
        if(arr[arr[arr[i]]] == i){
            res = true;
            break;
        }
    }
    
    if(res){
        cout << "YES";
    } else {
        cout << "NO";
    }
    
}