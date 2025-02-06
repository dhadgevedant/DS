#include<iostream>
#include<string>
#include<vector>
#include<cmath>
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

 void printTree(BT* root, int level = 0) {
        if (root == nullptr) return;
        
        // Calculate the maximum height of the tree
        int height = getHeight(root);
        
        // Create a vector of vectors to store node positions
        vector<vector<string>> levels(height, vector<string>(pow(2, height) - 1, " "));
        
        // Fill the levels vector with tree nodes
        fillLevels(root, 0, 0, pow(2, height) - 1, levels);
        
        // Print the tree
        for (const auto& level : levels) {
            for (const string& node : level) {
                cout << node;
            }
            cout << endl;
        }
    }
        // Display function to show the tree in an in-order fashion (optional)
    void display(BT* root) {
        if (root == nullptr) return;

        display(root->l);
        cout << root->data << " ";
        display(root->r);
    }

    //height of tree for
    int getHeight(BT* root) {
        if (root == nullptr) return 0;
        return 1 + max(getHeight(root->l), getHeight(root->r));
    }
    
    //fill vector with indentation and data
    void fillLevels(BT* root, int level, int left, int right, vector<vector<string>>& levels) {
        if (root == nullptr) return;
        
        int mid = (left + right) / 2;
        
        //print data
        levels[level][mid] = string(1, root->data);
        
        // giving space if there are children
        if (root->l != nullptr) {
            // leaving space for left children
            for (int i = mid - 1; i > (left + mid) / 2; i--) {
                levels[level][i] = " ";
            }
            levels[level][(left + mid) / 2] = " ";
        }
        
        if (root->r != nullptr) {
            // leaving space for right children
            for (int i = mid + 1; i < (mid + right) / 2; i++) {
                levels[level][i] = " ";
            }
            levels[level][(mid + right) / 2] = " ";
        }
        
        // filling levels with spaces
        fillLevels(root->l, level + 1, left, mid, levels);
        fillLevels(root->r, level + 1, mid + 1, right, levels);
    }


};



int main() {
    int ch;
    bool flag = true;

    BT binary_tree;

    while (flag) {
        system("clear"); 
        cout << "Current Tree Structure: \n";
        binary_tree.printTree(root); 

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
        cin.ignore();  
    }

    return 0;
}
