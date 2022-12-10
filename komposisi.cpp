#include <bits/stdc++.h>
#include <iostream>
#include <cstring>

using namespace std;

struct PQueueNode {
    int data;
    char data2[100];
    PQueueNode *next;
};

// Default priority: minimum
struct PriorityQueue
{
    PQueueNode *_top;
    double _size;

    void init()
    {
        _top = NULL;
        _size = 0;
    }

    bool isEmpty() {
        return (_top == NULL);
    }

    void push(char barang[], int value)
    {
        _size++;
        PQueueNode *temp = _top;
        PQueueNode *newNode = \
            (PQueueNode*) malloc (sizeof(PQueueNode));
        newNode->data = value;
        strcpy(newNode->data2, barang);
        newNode->next = NULL;

        if (isEmpty()) {
            _top = newNode;
            return;
        }

        if (value < _top->data) {
            newNode->next = _top;
            _top = newNode;
        }
        else {
            while ( temp->next != NULL && 
                    temp->next->data < value)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void pop()
    {
        if (!isEmpty()) {
            PQueueNode *temp = _top;
            _top = _top->next;
            free(temp);
        }
    }

    string top()
    {
        if (!isEmpty()) return _top->data2;
        else exit(-1);
    }

    unsigned size() {
        return _size;
    }
};

int main()
{
    PriorityQueue myq;

    myq.init();

    double N, M;
    cin >> N >> M;
    double arr[100];
    int x = 0;
    

    while(N--){
        char temp[100];
        cin >> temp;
        char cmp[] = "GASS";
        if(strcmp(temp,cmp) == 0){
            double total = 0;
            PQueueNode *tp = myq._top;
            while(tp!=NULL){
                total += tp->data;
                tp = tp->next;
                
            }
            double res = total/myq._size;
            arr[x] = res;
            x++;
            cout << fixed << setprecision(2) << res << endl;
        } else {
            int harga;
            cin >> harga;
            myq.push(temp, harga);
        }
    }

    double total = 0;
            PQueueNode *tp = myq._top;
            while(tp!=NULL){
                total += tp->data;
                tp = tp->next;
                
            }
            double res = total/myq._size;
    int y = x;
    double tot = 0;
    int in = 0;
    
    for(int i = 0; i < x; i++){
        tot += arr[i];

    }
     cout << fixed << setprecision(2) << tot/y << " ";
    if(res >= M - (M/2) && res <= M + (M/2)) {
        cout << "AMAN";
    } else {
        cout << "LOH";
    }
    return 0;
}