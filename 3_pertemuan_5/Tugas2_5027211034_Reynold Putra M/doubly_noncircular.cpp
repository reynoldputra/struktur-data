#include <iostream>
using namespace std;


typedef struct snode_t {
    int data;
    struct snode_t *prev;
    struct snode_t *next;
} Node;

typedef struct slist_t {
    unsigned _size;
    Node *_head;
    Node *_tail;
} DoubleList;



void slist_init(DoubleList *list) 
{
    list->_head = NULL;
    list->_tail = NULL;
    list->_size = 0;
}

bool slist_isEmpty(DoubleList *list) {
    return (list->_head == NULL);
}

void slist_pushBack(DoubleList *list, int value)
{
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;
        
        if (slist_isEmpty(list)) {
            list->_head = newNode;
            list->_tail = newNode;
        } else {
            Node *temp = list->_tail;
            temp->next = newNode;
            newNode->prev = temp;
            list->_tail = newNode;
        }
    }
}

void slist_pushfront(DoubleList *list, int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if(newNode){
        newNode->data = value;
        list->_size++;

        if(slist_isEmpty(list)){
            list->_head = newNode;
            list->_tail = newNode;
        } else {
            newNode->next = list->_head;
            newNode->next->prev = newNode;
            list->_head = newNode;
        }
    }
}

void slist_insertAt(DoubleList *list, int value, int index){
     if(slist_isEmpty(list)){
        slist_pushBack(list, value);
        return;
    } else if (index == 0){
        slist_pushfront(list, value);
        return;
    }

    Node *newNode = (Node*) malloc(sizeof(Node));

    if(newNode){
        list->_size++;
        Node* temp = list->_head;
        int i = 0;

        while(temp->next != NULL && i<index-1 || i>list->_size){
            temp = temp->next;
            i++;
        }

        newNode->data = value;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
}


void printls(DoubleList* list){
    Node* temp = list->_head;
    int i = 0;
    while (i<list->_size)
    {
        i++;
        cout << temp->data << " ";
        if(temp == list->_tail){
            break; 
        }
        temp = temp->next;
    }
    cout << endl;
}

void printls_reverse(DoubleList* list){
    Node* temp = list->_tail;
    int i = 0;
    while (true)
    {
        cout << temp->data << " ";
        if(temp == list->_head){
            break; 
        }
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    DoubleList myList;
    slist_init(&myList);

    slist_pushBack(&myList, 12);
    slist_pushBack(&myList, 247);
    slist_pushBack(&myList, 1238);
    slist_pushBack(&myList, 2);

    printls(&myList);

    slist_pushfront(&myList, 43);
    
    printls(&myList);

    slist_insertAt(&myList, 5345, 3);

    printls(&myList);
    
    printls_reverse(&myList);
    return 0;
}