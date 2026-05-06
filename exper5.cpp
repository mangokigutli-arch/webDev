/*AIM:
Company maintains employee information as employee ID, name, designation and salary.
Allow user to add, delete information of employee. 
Display information of particular employee.
If employee does not exist an appropriate message is displayed.
If it is, then the system displays the employee details. 
Use sequential file to maintain the data.

1. Create File
2. Open File
3. Read File
4. Write in File
5. Update in File
6. Search in File
7. Display File

INPUT: Employee Information

OUTPUT: Employee Information in Sequential File  

Author: Dr. Sunil Damodar Rathod.

DATE:16.03.2026

*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>   // for remove, rename
using namespace std;

struct Employee {
    int id;
    char name[20];
    char desig[20];
    float salary;
};

class FileSystem {
    Employee e;

public:

    // INSERT RECORD
    void insert() {
        ofstream fout("emp.dat", ios::binary | ios::app);

        if (!fout) {
            cout << "File error!\n";
            return;
        }

        cout << "Enter ID: ";
        cin >> e.id;

        cin.ignore(); // clear buffer

        cout << "Enter Name: ";
        cin.getline(e.name, 20);

        cout << "Enter Designation: ";
        cin.getline(e.desig, 20);

        cout << "Enter Salary: ";
        cin >> e.salary;

        fout.write((char*)&e, sizeof(e));
        fout.close();

        cout << "Record Inserted Successfully\n";
    }

    // DISPLAY ALL RECORDS
    void display() {
        ifstream fin("emp.dat", ios::binary);

        if (!fin) {
            cout << "File not found!\n";
            return;
        }

        cout << "\n--- Employee Records ---\n";

        int flag = 0;
        while (fin.read((char*)&e, sizeof(e))) {
            cout << "\nID: " << e.id;
            cout << "\nName: " << e.name;
            cout << "\nDesignation: " << e.desig;
            cout << "\nSalary: " << e.salary << "\n";
            flag = 1;
        }

        if (!flag)
            cout << "No records found!\n";

        fin.close();
    }

    // SEARCH RECORD BY NAME
    void search(char name[]) {
        ifstream fin("emp.dat", ios::binary);

        if (!fin) {
            cout << "File not found!\n";
            return;
        }

        int found = 0;

        while (fin.read((char*)&e, sizeof(e))) {
            if (strcmp(e.name, name) == 0) {
                cout << "\nRecord Found:\n";
                cout << "ID: " << e.id << endl;
                cout << "Name: " << e.name << endl;
                cout << "Designation: " << e.desig << endl;
                cout << "Salary: " << e.salary << endl;
                found = 1;
            }
        }

        if (!found)
            cout << "Record Not Found!\n";

        fin.close();
    }

    // DELETE RECORD
    void removeRecord(char name[]) {
        ifstream fin("emp.dat", ios::binary);
        ofstream fout("temp.dat", ios::binary);

        if (!fin || !fout) {
            cout << "File error!\n";
            return;
        }

        int found = 0;

        while (fin.read((char*)&e, sizeof(e))) {
            if (strcmp(e.name, name) != 0) {
                fout.write((char*)&e, sizeof(e));
            } else {
                found = 1;
            }
        }

        fin.close();
        fout.close();

        remove("emp.dat");
        rename("temp.dat", "emp.dat");

        if (found)
            cout << "Record Deleted Successfully\n";
        else
            cout << "Record Not Found\n";
    }

    // UPDATE RECORD
    void update(char name[]) {
        fstream file("emp.dat", ios::binary | ios::in | ios::out);

        if (!file) {
            cout << "File not found!\n";
            return;
        }

        int found = 0;

        while (file.read((char*)&e, sizeof(e))) {
            if (strcmp(e.name, name) == 0) {

                cout << "\nEnter New Data:\n";

                cout << "Enter ID: ";
                cin >> e.id;

                cin.ignore();

                cout << "Enter Name: ";
                cin.getline(e.name, 20);

                cout << "Enter Designation: ";
                cin.getline(e.desig, 20);

                cout << "Enter Salary: ";
                cin >> e.salary;

                file.seekp(-sizeof(e), ios::cur);
                file.write((char*)&e, sizeof(e));

                cout << "Record Updated Successfully\n";

                found = 1;
                break;
            }
        }

        if (!found)
            cout << "Record Not Found\n";

        file.close();
    }
};

int main() {
    FileSystem f;
    int ch;
    char name[20];

    do {
        cout << "\n\n===== MENU =====";
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Update";
        cout << "\n5. Delete";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";

        cin >> ch;

        switch (ch) {

        case 1:
            f.insert();
            break;

        case 2:
            f.display();
            break;

        case 3:
            cin.ignore();
            cout << "Enter name to search: ";
            cin.getline(name, 20);
            f.search(name);
            break;

        case 4:
            cin.ignore();
            cout << "Enter name to update: ";
            cin.getline(name, 20);
            f.update(name);
            break;

        case 5:
            cin.ignore();
            cout << "Enter name to delete: ";
            cin.getline(name, 20);
            f.removeRecord(name);
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (ch != 6);

    return 0;
}