#include <iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
} Node;



//EMPTY
int isEmpty(){
    if(head == NULL) return 1;
    return 0;
}

//INSERT
void pushBack(int val){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node){
        
        new_node->data = val;
        new_node->next = NULL;

        if(isEmpty()){
            head = new_node;
        } else {
            Node *temp = head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = new_node;
        }
    }
}

void pushFront(int val){
    Node *new_node = (Node*) malloc(sizeof (Node));
    if(new_node){
        new_node->data = val;

        if(isEmpty()) head = new_node;
        else {
            new_node->next = head;
            head = new_node;
        }
    }
}

void insertAt(int index, int val){
    if(isEmpty()){
        pushBack(val);
        return;
    } else if (index == 0){
        pushFront(val);
        return;
    }

    Node *new_node = (Node*) malloc(sizeof (Node));

    if(new_node){
        Node* temp = head;
        int i = 0;

        while(temp->next != NULL && i<index-1){
            temp = temp->next;
            i++;
        }

        new_node->data = val;
        new_node->next = temp->next;
        temp->next = new_node;
    }
}


//DELETE
void popBack(){
    if(!isEmpty()){
        Node* next = head->next;
        Node* curr = head;

        while(next->next != NULL){
            curr = next;
            next = next->next;
        }

        curr->next = NULL;
        free(next);
    }
}

void popFront(){
    if(!isEmpty()){
        Node* temp = head->next;
        head = temp;
        free(temp);
    }
}

void remove(int index){
    if(isEmpty()){
        return;
    }

    Node *new_node = (Node*) malloc(sizeof (Node));
    if(new_node){
        Node* temp = head;
        int i = 0;

        while (i < index-1) {
            temp = temp->next;
            i++;
        }

        Node* temp2 = temp->next;
        temp->next = temp2->next;

        free(temp2);
    }
}

//UPDATE
void upFront(int val){
    if(!isEmpty()) head->data = val;
}

void upBack(int val){
    if(!isEmpty()){
        Node *temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->data = val;
    }
}

void changeAt(int val, int index){
    if(!isEmpty()){
        Node* temp = head;
        int i = 0;

        while(temp->next != NULL && i<index-1){
            temp = temp->next;
            i++;
        }

        temp->data = val;
    }

}

//PRINT
void printls(){
    Node* temp = head;
    while (true)
    {
        cout << temp->data << " ";
        if(temp->next == NULL){
            break; 
        }
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    //TEST INSERT
    pushBack(2);
    printls();
    pushBack(3);
    printls();
    pushFront(1);
    pushFront(6);
    pushFront(7);
    printls();
    insertAt(2,4);
    printls();

    //TEST DELETE
    remove(3);
    printls();
    popBack();
    printls();
    popFront();
    printls();

    //TEST UPDATE
    upFront(1);
    printls();
    changeAt(2,2);
    printls();
    upBack(3);
    printls();
}