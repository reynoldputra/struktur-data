#include <iostream>
#include <vector>
using namespace std;


int main(){
    int N;
    int i = 1;
    cin >> N;
    vector<int> ga;
    vector<int> ge;

    while (N--)
    {  
        int x;
        cin >> x;
        if(i%2 == 0){
            ge.push_back(x);
        } else {
            ga.push_back(x);
        }
        i++;
    }

    for (int i = 0; i < ga.size(); i++)
    {
        cout << ga[i] << " ";
    }
    
    for (int i = 0; i < ge.size(); i++)
    {
        cout << ge[i] << " ";
    }
    

}