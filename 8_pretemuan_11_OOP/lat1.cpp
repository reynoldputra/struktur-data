#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {

    public:
        string MHSname;

        void getName(){
            cout << MHSname << endl;
        }
};

int main(){
    Mahasiswa mhs1;
    mhs1.MHSname = "Rahmat Budi";
    mhs1.getName();
}