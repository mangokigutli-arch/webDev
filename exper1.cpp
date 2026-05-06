/*A Dictionary stores keywords & its meanings.
Provide facility for:
i. adding new keywords
ii. deleting keywords
iii. updating values of any entry.
iv. Provide facility to display whole data sorted in ascending/ Descending order.
v. Also find how many maximum comparisons may require for finding any keyword.
Use Binary Search Tree for implementation.

INPUT: A word & its meaning

OUTPUT:BST of dictionary words */

#include<iostream>
using namespace std;

struct Node {
    string word, meaning;
    Node *left, *right;
};

class BST {
    Node *root;

public:
    BST() {
        root = NULL;
    }

    // Insert Node
    Node* insert(Node* root, string w, string m) {
        if (root == NULL) {
            Node* temp = new Node;
            temp->word = w;
            temp->meaning = m;
            temp->left = temp->right = NULL;
            return temp;
        }

        if (w < root->word)
            root->left = insert(root->left, w, m);
        else if (w > root->word)
            root->right = insert(root->right, w, m);
        else
            cout << "Duplicate word!\n";

        return root;
    }

    void add(string w, string m) {
        root = insert(root, w, m);
    }  

    // Display Ascending (Inorder)
    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->word << " : " << root->meaning << endl;
            inorder(root->right);
        }
    }

    // Display Descending
    void descending(Node* root) {
        if (root != NULL) {
            descending(root->right);
            cout << root->word << " : " << root->meaning << endl;
            descending(root->left);
        }
    }

    // Search Node
    void search(string key) {
        Node* temp = root;
        int count = 0;

        while (temp != NULL) {
            count++;
            if (key == temp->word) {
                cout << "Found! Comparisons: " << count << endl;
                return;
            }
            else if (key < temp->word)
                temp = temp->left;
            else
                temp = temp->right;
        }
        cout << "Word not found!\n";
    }

    // Update Meaning
    void update(string key) {
        Node* temp = root;

        while (temp != NULL) {
            if (key == temp->word) {
                cout << "Enter new meaning: ";
                cin >> temp->meaning;
                return;
            }
            else if (key < temp->word)
                temp = temp->left;
            else
                temp = temp->right;
        }
        cout << "Word not found!\n";
    }

    Node* getRoot() {
        return root;
    }
};

int main() {
    BST tree;
    int choice;
    string word, meaning;

    do {
        cout << "\n1.Add\n2.Display\n3.Update\n4.Search\n5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter word: ";
            cin >> word;
            cout << "Enter meaning: ";
            cin >> meaning;
            tree.add(word, meaning);
            break;

        case 2:
            cout << "\nAscending Order:\n";
            tree.inorder(tree.getRoot());

            cout << "\nDescending Order:\n";
            tree.descending(tree.getRoot());
            break;

        case 3:
            cout << "Enter word to update: ";
            cin >> word;
            tree.update(word);
            break;

        case 4:
            cout << "Enter word to search: ";
            cin >> word;
            tree.search(word);
            break;

        case 5:
            cout << "Exit\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}