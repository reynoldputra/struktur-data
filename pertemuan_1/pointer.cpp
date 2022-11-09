#include <iostream>
using namespace std;


int main(){
    string str = "Reynold";
    cout << "str : " << str << endl; 
    cout << "&str : " << &str << endl; //alamat variabel nama awal
    string *str2 = &str;
    cout << "*str2 : " << *str2 << endl; //direference variable kedua
    *str2 = "anap";
    cout << "*str2 : " << *str2 << endl; //merubah value variable pertama melalui variable kedua
    cout << "str2 : " << str2;

    return 0;
}