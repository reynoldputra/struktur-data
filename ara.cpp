#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<long> v;
    int N;
    int count = 0;
    cin >> N;

    while (N--) {
        int M;
        cin >> M;
        int minSize = 0;
        while (M--)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        
        sort(v.begin(), v.end());


        count += (v[v.size()-1]- v[0]);
        v.pop_back();
        v.pop_back();
        for (int i = 0; i < v.size(); i++) {
            v[i] = v[i + 1];
        }
    }
    cout << count;
}