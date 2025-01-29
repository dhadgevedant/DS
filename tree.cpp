#include<iostream>
using namespace std;

class Emp;
Emp *root;

class Emp{
     
     public:
          
          int id;
          Emp *lc, *rc;
     
          void create(){
               
               //allocating space to root node
               root = new Emp;
               root->lc = root->rc = NULL;
               
               //taking input and storing data 
               cout<<"Enter id: ";
               cin>>root->id;  
          }
          
          void insert( Emp *a, Emp *b = root){
               
               char ch;
               cout<<"Where do you want to insert(l/r): ";
               cin>>ch;
               
               if(ch =='l'){
                    
                    if(b->lc == NULL){
                         b->lc = a;
                    }
                    else{
                         insert(a,b->lc);
                    }
               }
               else{
               
                    if(b->rc == NULL){
                         b->rc = a;
                    }
                    else{
                         insert(a,b->rc);
                    }
               
               }
          }

};
void display(Emp *a){
     
     if(a == NULL)return;
     
     display(a->lc);
     cout<<a->id<<endl;
     display(a->rc);          
}
int main(){

     Emp a;
     
     a.create();
     
     Emp *next = new Emp;
     cout<<"Enter id of next node: ";
     cin>>next->id;
     
     a.insert(next,root);
     
     next = new Emp;
     cout<<"Enter id of next node: ";
     cin>>next->id;
     
     a.insert(next,root);
     
      next = new Emp;
     cout<<"Enter id of next node: ";
     cin>>next->id;
     
     a.insert(next,root);
     

     
     //cout<<root->id<<"  "<<root->lc->id;  
     display(root);
     return 0;
}
