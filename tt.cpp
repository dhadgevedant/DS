#include<iostream>
#include<iomanip>
using namespace std;

class BT;
BT* root = nullptr;

class BT {
public:
    char data;
    BT* l, * r;

    BT(char d = ' ') {
        data = d;
        l = r = nullptr;
    }
    void display(BT *root){

          if(root == nullptr)return;

          display(root->l);
          cout<<root->data<<" ";
          display(root->r);
     }
    

    void insert(BT* a, BT* b = root) {
        cout << "Insert Node (l/r): ";
        char ch; cin >> ch;

        if (ch == 'l') {
            if (b->l == nullptr) b->l = a;
            else insert(a, b->l);
        } else if (ch == 'r') {
            if (b->r == nullptr) b->r = a;
            else insert(a, b->r);
        }
    }

    void add() {
        cout << "Enter data: ";
        char d; cin >> d;

        BT* newnode = new BT(d);

        if (root == nullptr) {
            root = newnode;
        } else {
            insert(newnode);
        }
    }

  // Previous insert() and add() functions remain the same...

    void printTree(BT* root, int space = 0) {
        // Base case
        if (root == nullptr) return;

        // Increase distance between levels
        space += 4;

        // Process right child first
        printTree(root->r, space);

        // Print current node
        cout << endl;
        for (int i = 4; i < space; i++)
            cout << " ";
        cout << root->data;

        // Process left child
        printTree(root->l, space);
    }

};



int main() {
    int ch;
    bool flag = true;

    BT binary_tree;

    while (flag) {
        system("clear");  // Use system("cls") on Windows
        cout << "Current Tree Structure: \n";
        binary_tree.printTree(root);  // Print the tree structure

        cout << "\n\nMain Menu\n\n\t1. Add new node\n\t2. Display nodes\n\t3. Exit\n\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                binary_tree.add();
                break;

            case 2:
                cout << "In-order traversal: ";
                binary_tree.display(root);
                cout << endl << endl;
                //cout << "\nPress Enter to Continue...";
                cin.ignore();
                break;

            case 3:
                flag = false;
                break;
        }

        cout << "\nPress Enter to Continue...";
        cin.ignore();  // Clear the input buffer before taking input again
        //cin.get();     // Wait for the user to press Enter
    }

    return 0;
}
