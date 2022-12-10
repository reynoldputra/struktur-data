#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    vector<int> cek (101, 0);
    vector<int> data;

    int c = 1;
    while (c)
    {
        cin >> c;
        if(!c) break;
        if(!cek[c]) data.push_back(c);
        cek[c] = 1;
    }

    sort(data.begin(), data.end());

    for(int i = 0; i < data.size(); i++){
        cout << data[i] << endl;
    }

}