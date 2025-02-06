#include<iostream>
#include <queue>
using namespace std;

class BT;
BT *root;

class BT{

     public: 

     char data;
     BT *l, *r;

     BT(){
          l = nullptr;
          r = nullptr;
     }

     void insert( BT *a, BT *b = root){
                         
          cout<<"Insert Node(l/r): ";
          char ch;cin>>ch;
                    
          if(ch =='l'){ 
               if(b->l == NULL)b->l = a;
               else insert(a,b->l);
          }
          else{
               if(b->r == NULL)b->r = a;
               else insert(a,b->r);     
          }
     }
     void add(){

          cout<<"Enter data: ";
          char d; cin>>d;

          BT *newnode = new BT;
          newnode->data = d;

          if(root == nullptr)root = newnode;
          else{
               insert(newnode);
          }
     }
     void display(BT *root){

          if(root == nullptr)return;

          display(root->l);
          cout<<root->data<<" ";
          display(root->r);
     }

// Recursive function to print the tree in the desired format
void printTree(BT* root, string indent = "", bool isRight = false) {
    if (root == nullptr) return;

    // Print the current node with its indentation
    cout << indent;
    if (isRight) {
        cout << "    /";
        indent += "     ";
    } else {
        cout << "    \\";
        indent += "     ";
    }

    cout << root->data << endl;

    // Recurse for the right and left children
    if (root->r) {
        printTree(root->r, indent, true);  // Right child (isRight = true)
    }

    if (root->l) {
        printTree(root->l, indent, false); // Left child (isRight = false)
    }
}

};

int main(){

     int ch;
     bool flag = true;

     BT binary_tree;

     while(flag){

          system("clear");
          binary_tree.printTree(root);
          cout<<"\n\nMain Menue\n\n\t1. Add new node\n\t2. Display nodes\n\t3. Exit\n\nEnter your choice: ";
          cin>>ch;

          switch(ch){

               case 1:
                    binary_tree.add();
                    break;

               case 2:

                    cout<<"Tree: ";
                    binary_tree.display(root);
                    
                    cout << "\n\nPress Enter to Continue";
                    cin.ignore();
                    break;

               case 3:
                    flag = false;
                    break;
          }

          
          cout << "Press Enter to Continue";
          cin.ignore();

     }


     return 0;
}