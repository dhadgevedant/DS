// Assignment No. 3

/*  There are flight paths between the cities. if there is flight between city A and city B then there is an edge between the cities.
    - The cost of the edge may be time taken or required fuel in the journey.
    - The node represented airport name or name of the cities.
    - Use adjacency list and adjacency matrix.    */
    

#include <iostream>
using namespace std;

class GR 
{
  public:
    int v; 
    string city;
    int fuel; 
    GR *next; 
    
    void create(); 
    void addedge(); 
    void display(); 
} *Head[10]; 


void GR::create() 
{
    cout << "Enter the number of cities: ";
    cin >> v;
    cout << "\nEnter the names of the cities:\n";

   
    for(int i = 0; i < v; i++) 
    {
        Head[i] = new GR;  
        cout << "  Enter city " << (i + 1) << " name: ";
        cin >> Head[i]->city;
        Head[i]->next = NULL; 
    }
}


void GR::addedge() 
{
    int e;  
    string source, destination;
    int fuelRequired;  

    cout << "\nEnter the total number of edges: ";
    cin >> e;

    for (int i = 0; i < e; i++) 
    {
        cout << "\nEnter source and destination cities (space separated): ";
        cin >> source >> destination;
        
        cout << "Enter fuel required from " << source << " to " << destination << ": ";
        cin >> fuelRequired;


        GR *n1 = new GR;
        n1->city = destination;  
        n1->fuel = fuelRequired; 
        n1->next = NULL;

        
        bool found = false;
        for (int i = 0; i < v; i++) 
        {
            if (Head[i]->city == source) 
            {
                found = true;
                
                
                GR *temp = Head[i];
                while (temp->next != NULL) 
                {
                    temp = temp->next;
                }
                temp->next = n1;
                break;
            }
        }
        if (!found) 
        {
            cout << "\nSource city " << source << " not found!" << endl;
        }
    }
}


void GR::display() 
{
    for (int i = 0; i < v; i++) 
    {
        GR *temp = Head[i];
        cout << "\nFrom " << Head[i]->city << " City has flights: ";
        
        while (temp->next != NULL) 
        {
            temp = temp->next;
            cout << " to " << temp->city << " (Fuel Required: " << temp->fuel << ")\n";
        }
    }
}

int main()
{
    int ch;
    GR *a = new GR;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "  1. Create Graph\n";
        cout << "  2. Add Edge\n";
        cout << "  3. Display Graph\n";
        cout << "  4. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                a->create();
                break;
                
            case 2:
                a->addedge();
                break;
                
            case 3:
                a->display();
                break;
                
            case 4:
                return 0;
                
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }
}
