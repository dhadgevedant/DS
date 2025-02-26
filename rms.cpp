#include<iostream>
using namespace std;

class RMS *root;

class RMS{

    public:

        int price;
        string name;

        RMS *l, *r;

        RMS(){
            l = nullptr;
            r = nullptr;
            cout<<"root created";
        }

        void create(int p, string n){

            RMS *newnode;
            newnode = new RMS;
            newnode->price = p;
            newnode->name = n;

            if(root == nullptr){
                root = newnode;
            }
            else{
                insert(newnode);
            }
        }

        void insert(RMS *newnode, RMS *current = root){
            if(newnode->price < current->price){
                if(current->l == nullptr){
                    current->l = newnode;
                }
                else{
                    insert(newnode, current->l);
                }
            }
            else{
                if(current->r == nullptr){
                    current->r = newnode;
                }
                else{
                    insert(newnode, current->r);
                }
            }
        }

        void search( RMS *target, RMS *current = root){
            
            if (root == nullptr){
                
                cout<<"tree is empty";
                return;
            }
            if(target->price == current->price){

                cout<<"found";
                return;
            }
            else if(target->price < current->price){
                if(current->l == nullptr){
                    cout<<"not found";
                    return;
                }
                else{
                    search(target, current->l);
                }
            }
            else {
                if(current->r == nullptr){
                    cout<<"not found";
                    return;
                }
                else{
                    search(target, current->r);
                }
            }
        }

        void dlt(RMS *target, RMS *parent){

            //target has no child
            if(target->l == nullptr && target->r == nullptr){
                delete target;
                return;
            }
            //target has one child
            else if(target->l == nullptr || target->r == nullptr){

                //if targer is root
                if(parent == nullptr){
                    //root has children on right
                    if(target->l == nullptr){
                        root = target->r;
                        delete target;
                    }
                    //root has children on left
                    else{
                        root = target->l;
                        delete target;
                    }
                }
                //if target has children on right
                if(target->l == nullptr){
                    
                    //if target is present on right of the  parent
                    if(parent->r = target){
                        RMS *temp = parent->r;
                        parent->r = temp->r;
                        delete temp;
                    }
                    //if target is present on left of the  parent
                    else{
                        RMS *temp = parent->l;
                        parent->l = temp->r;
                        delete temp;
                    } 
                }
                //if target has children on left
                else{
                    //if target is present on right of the parent
                    if(parent->r = target){
                        RMS *temp = parent->r;
                        parent->r = temp->l;
                        delete temp;
                    }
                    //if targer is present on left of the parent
                    else{
                        RMS *temp = parent->l;
                        parent->l = temp->l;
                        delete temp;
                    }
                }
            }
            //target has two children
            else{

                //if target is root
                if(parent == nullptr){
                    
                    RMS *temp = root->l;//right most child on the left, i.e. greatest child on left
                    while(temp->r != nullptr){
                        temp = temp->r;
                    }

                    temp->r = root->r;
                    delete target;
                    root = target->l;
                }
                else{

                    RMS *temp = target->l;
                    while(temp->r != nullptr){
                        temp = temp->r;
                    }
                    
                    //linking parent to children of deleted target
                    if(parent->l == target){
                        parent->l = target->l;
                    }
                    else{
                        parent->r = target->l;
                    }
                    //deleting targer
                    temp->r = target->r;
                    delete target;
                }
            }
        }

        void delete_node(RMS *target){
         
            RMS *temp = root;
            while(target->l->price != temp->price || target->r->price != temp->price){

                if(target->l->price < temp->price){
                    temp = temp->l;
                }
                else{
                    temp = temp->r;
                }
            }
            dlt(target,temp);

        }

        void preorder(RMS *current = root){
            if(current == nullptr){
                return;
            }
            cout<<"Rupee. "<<current->price<<" -> "<<current->name<<endl;
            preorder(current->l);
            preorder(current->r);
        }

};

void pressEnterToContinue(){
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();

}

int main(){

    RMS obj;
    int choice;
    int p;
    string n;
    RMS *target;
    do{
        cout<<"\n1. Create\n2. Search\n3. Delete\n3. Preorder\n5. Exit\n";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter price and name: ";
                cin>>p>>n;
                obj.create(p, n);
                
                system("clear");
                break;
            
            case 2:
                cout<<"Enter price to search: ";
                cin>>p;
                target = new RMS;
                target->price = p;
                obj.search(target);
                
                pressEnterToContinue();
                system("clear");
                break;
            case 3:
                cout<<"Enter price to delete: ";
                cin>>p;
                target = new RMS;
                target->price = p;
                obj.delete_node(target);
                
                pressEnterToContinue();
                system("clear");
                break;
            case 4:
                obj.preorder();
                
                pressEnterToContinue();
                system("clear");
                break;   
            case 5:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice\n";
                pressEnterToContinue();
                system("clear");
        }

    }while(choice != 5);        

    return 0;
}