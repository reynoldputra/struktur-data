#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
    protected:
        string MHSname;

    public:
        Mahasiswa(string mhs) {
            MHSname = mhs;
        }

        void getName(){
            cout << MHSname << endl;
        }
};

int main(){
    Mahasiswa mhs1("Rahmat Budi");
    mhs1.getName();
}