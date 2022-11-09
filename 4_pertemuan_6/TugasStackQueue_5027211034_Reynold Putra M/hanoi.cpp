#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

// Node structure
struct StackNode {
    int data;
    StackNode *next;
};

/* Structure of Stack using List */
struct Stack
{
    StackNode *_top;
    unsigned _size;

    void init() 
    {
        _size = 0;
        _top = nullptr;
    }

    bool isEmpty() {
        return (_top == nullptr);
    }

    void push(int value)
    {
        StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
        if (newNode) {
            _size++;
            newNode->data = value;

            if (isEmpty()) newNode->next = NULL;
            else newNode->next = _top;
            _top = newNode;
        }
    }

    void pop()
    {
        if (!isEmpty()) {
            StackNode *temp = _top;
            _top = _top->next;
            free(temp);
            _size--;
        }
    }

    int top()
    {
        if (!isEmpty())
            return _top->data;
        exit(-1);
    }

    void printst(){
        if(!isEmpty()){
            StackNode *temp = _top;
            int arr[_size];
            int i = 0;
            while( temp != NULL){
                arr[i] = temp->data;
                temp = temp->next;
                i++;
            }
            while(i--){
                cout << arr[i] << " ";
            }
        } else {
            cout << " ";
        }
    }
};

void printAllSt(Stack* st){
    cout << ">> ";
    st[0].printst();
    cout << endl;
    cout << ">> ";
    st[1].printst();
    cout << endl;
    cout << ">> ";
    st[2].printst();
    cout << endl;
    cout << "=========";
    cout << endl;
}

void move(Stack* tiang, Stack* start, Stack* end, int startInd, int endInd){
    cout << "## Cakram teratas dari tiang "<< startInd+1 << " pindah ke tiang " << endInd+1 << endl;
    printAllSt(tiang);
    int temp = start->top();
    start->pop();
    end->push(temp);
}

void solve(int disk, Stack* tiang, Stack* start, Stack* end, int startInd, int endInd){
    if (disk == 1) {
        move(tiang, start, end, startInd, endInd);
    } else {
        int other = 3 - (startInd + endInd);
        Stack *otherst = (tiang+(other));
        solve(disk-1, tiang, start, otherst, startInd, other);
        move(tiang, start, end, startInd, endInd);
        solve(disk-1, tiang, otherst, end, other, endInd);
    }
}

int main()
{
    Stack tiang[3];
    tiang[0].init();
    tiang[1].init();
    tiang[2].init();

    cout << "Masukan jumlah disk/cakram yang diinginkan : ";
    int disk;
    cin >> disk;
    int diskTemp = disk;

    while(diskTemp--){
        tiang[0].push(diskTemp+1);
    }
    
    int dest;
    while(true){
        cout << "Pilih tiang tujuan (2/3) : ";
        cin >> dest;
        if(dest == 2 || dest == 3) break;
    }
    solve(disk, &tiang[0], &tiang[0], &tiang[dest-1], 0, dest-1);
    cout << "## HASIL" << endl;
    printAllSt(tiang);


    return 0;
}