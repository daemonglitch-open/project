////in this code vector is not use to make the array operation hard, allong size dynamic memory allocation.
#include <iostream>
#include <vector>
using namespace std;


class arr_data{
    public:
        int o, n, i, e, p, s, u;
        vector<int> arr; // Dynamic array using vector
};

//pass by reference
void insert(arr_data &use), search(arr_data &use), update(arr_data &use), del(arr_data &use);


int main(){

    int option;
    arr_data use;

    cout << "\n                       :::::::::::::::::::::::::::::::::::::";
    cout << "\n                       ::                                 ::";
    cout << "\n                       ::     @@@@@@@@@@@@@@@@@@@@@@@     ::";
    cout << "\n                       ::     @                     @     ::";
    cout << "\n                       ::     @      WELCOME TO     @     ::";
    cout << "\n                       ::     @                     @     ::";
    cout << "\n                       ::     @    Programers4You   @     ::";
    cout << "\n                       ::     @                     @     ::";
    cout << "\n                       ::     @@@@@@@@@@@@@@@@@@@@@@@     ::";
    cout << "\n                       ::                                 ::";
    cout << "\n                       :::::::::::::::::::::::::::::::::::::\n" << endl;

    while(option != 5) {
        

        cout << "\n1- INSERTING " << endl;
        cout << "2- SEARCHING" << endl;
        cout << "3- UPDATING" << endl;
        cout << "4- DELETING" << endl;
        cout << "5- EXIT" << endl;
        cout << "Enter Your Option: ";
        cin >> option;

        switch(option){
            case 1:
                insert(use);  // i use pass by reference
                break;

            case 2:
                search(use);
                break;

            case 3:
                update(use);
                break;

            case 4:
                del(use);
                break;

            case 5:
                cout << "Exiting program." << endl;
                break;

            default:
              cout << "INVALID OPTION";
        }
    } 
    return 0;
}

void insert(arr_data &use){

    cout << "Enter the size of the array: ";
    cin >> use.n;
    
    //resise the vector
    use.arr.resize(use.n);
   
    cout << "Enter the elemnt: \n";
    for (use.i = 0; use.i < use.n; use.i++){
        cin >> use.arr[use.i];
    }

    for (use.i = 0; use.i < use.n; use.i++){
        cout << "Array Element: " << use.arr[use.i] << " ";
    }

    while(use.o != 4) {
        cout << "\n\t\t\tCHOOSE AN OPTION TO INSERT AN ELEMENT IN THE ARRAY" << endl;
        cout << "1- END " << endl;
        cout << "2- BEGINNING" << endl;
        cout << "3- ANY POSITION" << endl; 
        cout << "4- BACK"  << endl;
        cout << "Enter Option: " << endl;
        cin >> use.o;

        switch(use.o){
            case 1: 
                cout << "\nEnter the element: ";
                cin >> use.e;
                //use.arr.push_back(use.e); // Insert at the end
                use.n++;
                use.arr[use.n-1] = use.e;
                for (use.i = 0; use.i < use.n; use.i++){
                cout << "\nArray Element: " << use.arr[use.i] << " ";
                }       
                break;

            case 2:
                cout << "Enter the element: ";
                cin >> use.e;
                //use.arr.insert(use.arr.begin(), use.e); // Insert at the beginning
                for(use.i = use.n; use.i > 0; use.i--){
                    use.arr[use.i] = use.arr[use.i-1];
                }
                use.arr[0] = use.e;
                use.n++;
                for (use.i = 0; use.i < use.n; use.i++){
                cout << "\nArray Element: " << use.arr[use.i] << " ";
                }
                break;

            case 3:
                cout << "Enter the elememt: ";
                cin >> use.e;
                cout << "Enter the position: ";
                //cout << "Enter the position (1 to " << use.arr.size() + 1 << "): ";//to insert into the position
                cin >> use.p;

                if(use.p < 1 || use.p > use.n + 1){
                cout << "INVALID POSITION!" << endl;
                break;
                }

                //shift the position to the right
                for(use.i = use.n; use.i >= use.p; use.i--){
                use.arr[use.i] = use.arr[use.i-1];
                }

                //insert the new element
                use.arr[use.p-1] = use.e;

                //output the udated array
                for (use.i = 0; use.i < use.n + 1; use.i++){
                cout << "Index:" << use.i << " Element: " << use.arr[use.i] << endl;
                }
                break;

            case 4:
                break;

            default:
                cout << "INVALID OPTION!" << endl;
        }
    }
}

void search(arr_data &use){
    //reset use.o for each loop
    use.o = 0;
    
    while (use.o != 4){
        for (use.i = 0; use.i < use.n; use.i++){
            cout << "Array Element: " << use.arr[use.i] << " ";
        }  
        cout << "\nEnter the element to search for: ";
        cin >> use.s;

        cout << "\n\t\t\tSELECT A SEARCH ALGORITH" << endl;
        cout << "1- LINEAR SEARCH" << endl;
        cout << "2- BINARY SEARCH" << endl;
        cout << "3- JUMP SEARCH" << endl;
        cout << "4- BACK" << endl;
        cin >> use.o;

        
        switch(use.o){

            case 1:
                for(use.i = 0; use.i < use.n; use.i++){
                    if(use.s == use.arr[use.i]){
                        cout << "Element: " << use.s << " found at Index: " << use.i << endl;
                        break;
                    }                  
                }
                if(use.i == use.n){
                    cout << "Element: " << use.s << " is not in the array." << endl;
                }
                break;

            case 2:
                cout << "BINARY SEARCH IS NOT READY." << endl;
                break;
            
            case 3:
                cout << "JUMP SEARCH IS NOT READY." << endl;
                break;

            case 4:
                break;

            default:
                cout << "INVALID OPTION." << endl;
        }
    }
}


void update(arr_data &use){
    
    cout << "Array Element: ";
    // Display current array elements
    for (use.i = 0; use.i < use.n; use.i++){
        cout << use.arr[use.i] << " ";
    }

    // Ask user for the index to update
    cout << "Enter the index to update: (0 to " << use.n -1 << "): ";
    cin >>  use.u;

    // Validate index
    if (use.u < 0 || use.u >= use.n) {
        cout << "Invalid index! Please try again.\n";
        return;
    }

    cout << "Enter the new value for the element: ";
    cin >> use.e;

    //updatethe element at the specific index
    use.arr[use.u] = use.e;

    for (use.i = 0; use.i < use.n; use.i++){
        cout << "Updated Element: " << use.arr[use.i] << " ";
    }
}

void del(arr_data &use){
    cout << "Array Element: ";
    // Display current array elements
    for (use.i = 0; use.i < use.n; use.i++){
        cout << use.arr[use.i] << " ";
    }

    // Ask user for the index to update
    cout << "\nEnter the index to delete: (0 to " << use.n -1 << "): ";
    cin >>  use.u;

    // Validate index
    if (use.u < 0 || use.u >= use.n) {
        cout << "Invalid index! Please try again.\n";
        return;
    }

    // Shift elements to the left to remove the element at index `use.u`
    for (use.i = use.u; use.i < use.n - 1; use.i++) {
        use.arr[use.i] = use.arr[use.i + 1];
    }

    // Decrease the size of the array
    use.n--;
    use.arr.resize(use.n); // to adjust the vector size

    cout << "Updated Array: ";
    for (use.i = 0; use.i < use.n; use.i++) {
        cout << use.arr[use.i] << " ";
    }
}