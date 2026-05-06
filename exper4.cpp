
/*
AIM:
A Dictionary stores keywords & its meanings.
Use Binary Search Tree-AVL concept for implementation.
Provide facility to:
i. Insert new Keyword
ii.Display whole data sorted in dictionary.
iii. Use Height Balance Tree concept to balance the AVL

INPUT: Keyword - meaning
OUTPUT: Balanced AVL with keywords as the data 

Author: Dr. Sunil Damodar Rathod.
Date: 09.03.2023
*/

#include<iostream>
#include<cstring>
using namespace std;

struct Node {
    char key[20]; 
    char meaning[100];
    Node *left, *right;
};

class AVL {
    Node *root;

public:
    AVL() {
        root = NULL;
    }

    // Height function
    int height(Node *t) {
        if (t == NULL) return 0;
        return 1 + max(height(t->left), height(t->right));
    }

    // Balance Factor
    int getBF(Node *t) {
        if (t == NULL) return 0;
        return height(t->left) - height(t->right);
    }

    // Right Rotation (LL)
    Node* rightRotate(Node *y) {
        Node *x = y->left;
        y->left = x->right;
        x->right = y;
        cout << "\nLL Rotation";
        return x;
    }

    // Left Rotation (RR)
    Node* leftRotate(Node *x) {
        Node *y = x->right;
        x->right = y->left;
        y->left = x;
        cout << "\nRR Rotation";
        return y;
    }

    // Insert function
    Node* insert(Node *t, char key[], char meaning[]) {
        if (t == NULL) {
            Node *n = new Node;
            strcpy(n->key, key);
            strcpy(n->meaning, meaning);
            n->left = n->right = NULL;
            return n;
        }

        if (strcmp(key, t->key) < 0)
            t->left = insert(t->left, key, meaning);
        else if (strcmp(key, t->key) > 0)
            t->right = insert(t->right, key, meaning);
        else
            return t;

        int bf = getBF(t);

        // LL Case
        if (bf > 1 && strcmp(key, t->left->key) < 0)
            return rightRotate(t);

        // RR Case
        if (bf < -1 && strcmp(key, t->right->key) > 0)
            return leftRotate(t);

        // LR Case
        if (bf > 1 && strcmp(key, t->left->key) > 0) {
            t->left = leftRotate(t->left);
            cout << "\nLR Rotation";
            return rightRotate(t);
        }

        // RL Case
        if (bf < -1 && strcmp(key, t->right->key) < 0) {
            t->right = rightRotate(t->right);
            cout << "\nRL Rotation";
            return leftRotate(t);
        }

        return t;
    }

    void insertWord(char key[], char meaning[]) {
        root = insert(root, key, meaning);
    }

    // Inorder display (sorted)
    void display(Node *t) {
        if (t != NULL) {
            display(t->left);
            cout << t->key << " : " << t->meaning << endl;
            display(t->right);
        }
    }

    void show() {
        display(root);
    }

    // Search
    void search(char key[]) {
        Node *cur = root;
        int count = 0;

        while (cur != NULL) {
            count++;
            if (strcmp(key, cur->key) == 0) {
                cout << "\nFound in " << count << " comparisons";
                return;
            }
            else if (strcmp(key, cur->key) < 0)
                cur = cur->left;
            else
                cur = cur->right;
        }
        cout << "\nNot Found";
    }
};

int main() {
    AVL tree;
    int ch;
    char key[20], meaning[100];

    do {
        cout << "\n1.Insert\n2.Display\n3.Search\n4.Exit\nChoice: ";
        cin >> ch;
        cin.ignore();

        switch (ch) {
        case 1:
            cout << "Enter word: ";
            cin.getline(key, 20);
            cout << "Enter meaning: ";
            cin.getline(meaning, 100);
            tree.insertWord(key, meaning);
            break;

        case 2:
            tree.show();
            break;

        case 3:
            cout << "Enter word: ";
            cin.getline(key, 20);
            tree.search(key);
            break;
        }
    } while (ch != 4);

    return 0;
}
