/*
Construct an expression tree from the given prefix expression 
eg. +--a*bc/def and 
traverse it using post-order traversal(non recursive) 
and then delete the entire tree.

INPUT: A prefix expression

OUTPUT: Expression tree

AUTHOR: Sunil Rathod

DATE:03.02.2026
*/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 20

// Node structure
struct Node {
    char data;
    Node *left, *right;
};

// Simple Stack for Node*
class Stack {
    Node* arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(Node* x) {
        arr[++top] = x;
    }

    Node* pop() {
        return arr[top--];
    }

    bool empty() {
        return top == -1;
    }
};

// Expression Tree class
class ExpTree {
    char exp[20];
    Node* root;

public:
    ExpTree() { root = NULL; }

    void read() {
        cout << "Enter Prefix Expression: ";
        cin >> exp;
    }

    bool isOperator(char c) {
        return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
    }

    void buildTree() {
        Stack s;

        for(int i = strlen(exp)-1; i >= 0; i--) {
            Node* temp = new Node;
            temp->data = exp[i];
            temp->left = temp->right = NULL;

            if(!isOperator(exp[i])) {
                s.push(temp);
            } else {
                temp->left = s.pop();
                temp->right = s.pop();
                s.push(temp);
            }
        }
        root = s.pop();
    }

    // Non-recursive Postorder
    void postorder() {
        if(root == NULL) return;

        Stack s1, s2;
        s1.push(root);

        while(!s1.empty()) {
            Node* temp = s1.pop();
            s2.push(temp);

            if(temp->left) s1.push(temp->left);
            if(temp->right) s1.push(temp->right);
        }

        cout << "Postorder: ";
        while(!s2.empty()) {
            cout << s2.pop()->data << " ";
        }
    }

    // Inorder (for checking)
    void inorder(Node* t) {
        if(t) {
            inorder(t->left);
            cout << t->data << " ";
            inorder(t->right);
        }
    }

    Node* getRoot() {
        return root;
    }
};

int main() {
    ExpTree e;
    int ch;

    do {
        cout << "\n1.Read\n2.Build\n3.Inorder\n4.Postorder\n5.Exit\nChoice: ";
        cin >> ch;

        switch(ch) {
            case 1: e.read(); break;
            case 2: e.buildTree(); break;
            case 3: e.inorder(e.getRoot()); break;
            case 4: e.postorder(); break;
        }
    } while(ch != 5);

    return 0;
}