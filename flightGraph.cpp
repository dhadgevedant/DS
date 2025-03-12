// Assignment No. 3

/*  There are flight paths between the cities. if there is flight between city A and city B then there is an edge between the cities.
    - The cost of the edge may be time taken or required fuel in the journey.
    - The node represented airport name or name of the cities.
    - Use adjacency list and adjacency matrix.    */
    

    #include<iostream>
    using namespace std;
    
    class Flight
    {
        int v;  
        char city[10][20];  
        int adjMatrix[10][10];  
    
    public:
        void accept();
        void display();
    };
    
    void Flight::accept() 
    {
        cout << "\nEnter the number of cities: ";
        cin >> v;
    
        cout << "Enter the city names:\n";
        for (int i = 0; i < v; i++) 
        {
            cout << "City " << i + 1 << ": ";
            cin >> city[i];
        }
    
        // Input adjacency matrix
        cout << "\nEnter adjacency matrix (Enter cost for each flight path, 0 if no path):\n";
        for (int i = 0; i < v; i++) 
        {
            for (int j = 0; j < v; j++) 
            {
                cout << "Enter cost from " << city[i] << " to " << city[j] << ": ";
                cin >> adjMatrix[i][j];
            }
        }
    }
    
    void Flight::display() 
    {
        cout << "\nAdjacency Matrix Representation:\n\n";
        cout << "\t";
        
       
        for (int i = 0; i < v; i++) 
        {
            cout << city[i] << "\t";
        }
        cout << endl;
    
       
        for (int i = 0; i < v; i++) 
        {
            cout << city[i] << "\t";
            
            for (int j = 0; j < v; j++) 
            {
                cout << adjMatrix[i][j] << "\t";
            }
            cout << endl;
        }
    }
    
    int main() {
        Flight s;
        s.accept();
        s.display();
        return 0;
    }
    