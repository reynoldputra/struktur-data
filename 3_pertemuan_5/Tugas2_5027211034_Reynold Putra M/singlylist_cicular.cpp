#include <iostream>
using namespace std;


typedef struct snode_t {
    int data;
    struct snode_t *next;
} SListNode;

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
    SListNode *_tail;
} SinglyList;

void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pushBack(SinglyList *list, int value);
void printls(SinglyList* list);

void slist_init(SinglyList *list) 
{
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_pushBack(SinglyList *list, int value)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (slist_isEmpty(list)) {
            list->_head = newNode;
            list->_tail = newNode;
        } else {
            SListNode *temp = list->_tail;
            temp->next = newNode;
            newNode->next = list->_head;
            list->_tail = newNode;
        }
    }
}

void slist_pushfront(SinglyList *list, int value) {
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if(newNode){
        newNode->data = value;

        if(slist_isEmpty(list)){
            list->_head = newNode;
            list->_tail->next = newNode;
        }    
        else {
            newNode->next = list->_head;
            list->_head = newNode;
            list->_tail->next = newNode;
        }
    }
}

void slist_insertAt(SinglyList *list, int value, int index){
     if(slist_isEmpty(list)){
        slist_pushBack(list, value);
        return;
    } else if (index == 0){
        slist_pushfront(list, value);
        return;
    }

    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));

    if(newNode){
        SListNode* temp = list->_head;
        int i = 0;
        while(temp->next != NULL && i<index-1){
            temp = temp->next;
            i++;
        }

        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


void printls(SinglyList* list, int iteration){
    SListNode* temp = list->_head;
    int i = 0;
    while (i < iteration*list->_size)
    {
        cout << temp->data << " ";
        if(temp == list->_tail) cout << " | ";
        temp = temp->next;
        i++;
    }
    cout << endl;
}


int main()
{
    SinglyList myList;
    slist_init(&myList);

    slist_pushBack(&myList, 12);
    slist_pushBack(&myList, 247);
    slist_pushBack(&myList, 1238);
    slist_pushBack(&myList, 2);

    printls(&myList, 2);

    slist_pushfront(&myList, 43);
    
    printls(&myList, 3);

    slist_insertAt(&myList, 5345, 3);

    printls(&myList, 4);
  
    return 0;
}