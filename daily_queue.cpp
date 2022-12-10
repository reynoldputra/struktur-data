#include <iostream>
#include <queue>
using namespace std;


int main(){
    queue<int> q;
    int N;
    cin >> N;
    while (N--)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        queue<int> p = q;
        queue<int> c;
        bool flag = false;
        while (!p.empty())
        {
            c.push(p.front());
            if(p.front() > f) {
                flag = true;
                break;
            }
            p.pop();
        }


        if(!flag){
            cout << "letsgo!!" << endl;
            continue;
        }
        cout << c.size() << " ";
        while (!c.empty())
        {
            cout << c.front() << " ";
            c.pop();
        }

        cout << endl;
    }
    
    
}