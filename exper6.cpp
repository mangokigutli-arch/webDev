/*AIM:
Consider telephone book database of N clients.
Make use of a hash table implementation to quickly look up 
client‘s telephone number.
Make use of two collision handling techniques and 
compare them using number of comparisons required 
to find a set of telephone numbers.

INPUT: Client Information, name and telephone number

OUTPUT: Search and display Client telephone number

Author: Dr. Sunil Damodar Rathod.

DATE:09.04.2026

Linear Probing - hf=key%sizeoftable
Quadratic Probing - 
	i=1
	hi= (i^2+key)%sizeoftable
*/
#include<iostream>
using namespace std;

#define SIZE 5

struct Client {
    long int phone;
    string name;
};

int main() {
    Client table[SIZE];

    // initialize
    for(int i=0;i<SIZE;i++) {
        table[i].phone = -1;
        table[i].name = "";
    }

    int choice = 0;

    while(true) {
        cout<<"\n1.Insert\n2.Display\n3.Search\n4.Exit\n";
        cout<<"Enter choice: ";

        cin >> choice;

        // 🔴 IMPORTANT FIX: handle invalid input
        if(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout<<"Invalid input!\n";
            continue;
        }

        if(choice == 1) {
            long int phone;
            string name;

            cout<<"Enter phone and name: ";
            cin>>phone>>name;

            int index = phone % SIZE;

            // linear probing
            for(int i=0;i<SIZE;i++) {
                int pos = (index + i) % SIZE;

                if(table[pos].phone == -1) {
                    table[pos].phone = phone;
                    table[pos].name = name;
                    break;
                }
            }
        }
        else if(choice == 2) {
            cout<<"\nIndex\tPhone\tName\n";
            for(int i=0;i<SIZE;i++) {
                cout<<i<<"\t"<<table[i].phone<<"\t"<<table[i].name<<endl;
            }
        }
        else if(choice == 3) {
            long int phone;
            cout<<"Enter phone: ";
            cin>>phone;

            int index = phone % SIZE;
            bool found = false;

            for(int i=0;i<SIZE;i++) {
                int pos = (index + i) % SIZE;

                if(table[pos].phone == phone) {
                    cout<<"Found at index "<<pos<<endl;
                    found = true;
                    break;
                }
            }

            if(!found)
                cout<<"Not Found\n";
        }
        else if(choice == 4) {
            cout<<"Exit\n";
            break;
        }
        else {
            cout<<"Wrong choice\n";
        }
    }

    return 0;
}