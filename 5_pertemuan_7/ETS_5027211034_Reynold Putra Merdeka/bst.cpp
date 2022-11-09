
    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>
    #include <string>

    using namespace std;

    /* Node structure */

    struct BSTNode {
        BSTNode *left, *right;
        string key;
    };

    /* uniqueBST */

    struct BST {
        // Member
        BSTNode *_root;
        unsigned int _size;

        // Function
        void init() {
            _root = NULL;
            _size = 0u;
        }

        bool isEmpty() {
            return _root == NULL;
        }

        bool find(string val) {
            BSTNode *temp = __search(_root, val);
            if (!temp) return false;
            if (temp->key == val) return true;
            else return false;
        }

        void insertRight(string parent, string child) {
            if (!find(child)) {
                if(find(parent)){
                    BSTNode *temp = __search(_root, parent);
                    temp->right = __createNode(child);
                    _size++;
                }
            } 
        }

        void insertLeft(string parent, string child) {
            if (!find(child)) {
                if(find(parent)){
                    BSTNode *temp = __search(_root, parent);
                    temp->left = __createNode(child);
                    _size++;
                }
            } 
        }

        void rename(string val, string newVal) {
            if (!find(newVal)) {
                if(find(val)){
                    BSTNode *temp = __search(_root, val);
                    temp->key = newVal;
                }
            } 
        }

        void insertRoot(string parent){
            _root = __createNode(parent);
        }

        void traverseInorder() {
            __inorder(_root);
        }

        void traversePreorder() {
            __preorder(_root);
        }

        void traversePostorder() {
            __postorder(_root);
        }

    private:
        // Utility Function
        BSTNode* __createNode(string val) {
            BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
            newNode->key = val;
            newNode->left = newNode->right = NULL;
            return newNode;
        }
        
        BSTNode* __search(BSTNode *root, string val) {
            if (root == 0) return NULL;
            if (root->key == val ) return root;
            
            BSTNode *newNode1 = __search(root->left, val);
            if(newNode1 != 0) return newNode1;
            BSTNode *newNode2 = __search(root->right, val);
            if(newNode2 != 0) return newNode2;
            
            return NULL;
        }

        void __inorder(BSTNode *root) {
            if (root) {
                __inorder(root->left);
                cout << root->key << endl;
                __inorder(root->right);
            }
        }

        void __postorder(BSTNode *root) {
            if (root) {
                __postorder(root->left);
                __postorder(root->right);
                cout << root->key << endl;
            }
        }

        void __preorder(BSTNode *root) {
            if (root) {
                cout << root->key << endl;
                __preorder(root->left);
                __preorder(root->right);
            }
        }
    };

    void changeName(BST set){
        string temp1;
        string temp2;
        cout << "Choose a name to rename : ";
        cin >> temp1;
        cout << "New name (no space) : ";
        cin >> temp2;
        set.rename(temp1, temp2);
    }

    int main(int argc, char const *argv[])
    {
        BST set;
        set.init();

        set.insertRoot("Arya");
        set.insertLeft("Arya", "Bobby");
        set.insertRight("Arya", "Bayu");
        set.insertLeft("Bobby", "Lestari");
        set.insertRight("Bobby", "Abdul");
        set.insertLeft("Lestari", "Diana");
        set.insertLeft("Diana", "Hadi");
        set.insertRight("Diana", "Yuni");
        set.insertLeft("Yuni", "Ahmad");
        set.insertRight("Yuni", "Wulan");
        set.insertLeft("Bayu", "Surya");
        set.insertRight("Bayu", "Bagus");
        set.insertLeft("Bagus", "Aulia");
        set.insertLeft("Aulia", "Rini");
        set.insertRight("Aulia", "Fajar");
        set.insertLeft("Rini", "Eko");
        set.insertRight("Rini", "Putra");
        set.insertLeft("Fajar", "Aditya");

        cout << "Print (PreOrder) :" << endl;
        set.traversePreorder();
        changeName(set);
        set.traversePreorder();
        cout << "===========" << endl;
        cout << "Print (InOrder) :" << endl;
        set.traverseInorder();
        changeName(set);
        set.traverseInorder();
        cout << "===========" << endl;
        cout << "Print (PostOrder) :" << endl;
        set.traversePostorder();
        changeName(set);
        set.traversePostorder();
        cout << "===========" << endl;
        return 0;
    }