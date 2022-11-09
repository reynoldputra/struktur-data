
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

// Node Structure
struct QueueNode {
    char nama[100];
    char alamat[100];
    long long norek;
    QueueNode *next;
};

/* Structure of Queue using List */
struct Queue
{
    QueueNode *_front, *_rear;
    unsigned _size;
    string nama;

    void init(string orang)
    {
        _size  = 0;
        _front = NULL;
        _rear  = NULL;
        nama   = orang;
    }

    int isEmpty() {
        if(_size == 0 ){
            return 1;
        } else {
            return 0;
        }
    }

    void push(char nama[], char alamat[], long long norek)
    {
        QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
        
            strcpy(newNode->nama, nama);
            newNode->norek = norek;
            strcpy(newNode->alamat, alamat);
            newNode->next = NULL;
            
            if (isEmpty()){
                _front = _rear = newNode;
            }         
            else {
                _rear->next = newNode;
                _rear = newNode;
            }
            _size++;
        
    }

    void pushNode(QueueNode *newNode){
        QueueNode *temp = newNode;
        newNode->next = NULL;
        if (isEmpty())                 
            _front = _rear = newNode;
        else {
            _rear->next = newNode;
             _rear = newNode;
        }
        _size++;
    }

    void pop()
    {
        if (!isEmpty()) {
            QueueNode *temp = _front;
            _front = _front->next;
            free(temp);
            
            if (_front == NULL)
                _rear = NULL;
            _size--;
        }
    }

    void popNode()
    {
        if (!isEmpty()) {
            _front = _front->next;
            if (_front == NULL)
                _rear = NULL;
            _size--;
        }
    }

    QueueNode *front()
    {
        if (!isEmpty())
            return _front;
        exit(-1);
    }

    unsigned size() {
        return _size;
    }

    void printst(){
        QueueNode* temp = _front;
        cout << "[";
        while(temp != NULL){
            cout << "\"" << temp->nama << "\" ";
            temp = temp->next;
        }
        cout << "]";
    }
};

void solve(Queue* cs, Queue* kasir, int index){ 
    int i = 0;
    while(true){
        cout << "## Antrian " << i << endl;
        cout << "CS : ";
        cs->printst();
        cout << endl;
        cout << "Kasir : ";
        kasir->printst();
        cout << endl;
        if (cs->isEmpty()) break;
        QueueNode *temp = cs->front();
        cs->popNode();
        kasir->pushNode(temp);
        i++;
        cout << "==========" << endl;
    }
}

int main()
{
    Queue cs;
    cs.init("Anna");
    Queue kasir;
    kasir.init("Lia");

    int N;
    cout << "Masukan jumlah nasabah : ";
    cin >> N;

    int i = 1;
    int temp = N;
    cout << "==========" << endl;
    while(temp--){
        char nama[100];
        char alamat[100];
        long long norek;
        cout << "Nama nasabah ke " << i << " : ";
        cin >> nama;
        cout << "Alamat nasabah ke " << i << " : ";
        cin >> alamat;
        cout << "Nomor rekening nasabah ke " << i << " : ";
        cin >> norek;
        cs.push(nama, alamat, norek);
        cout << "==========" << endl;
        i++;
    }
    solve(&cs, &kasir, N);

    return 0;
}

/*
2
Reynold
Keputih
5027211034
Rifki
Asarama
5027211035
*/

/*
3
Reynold
Keputih
5027211034
Rifki
Asarama
5027211035
Anap
Makam
5027211038
*/