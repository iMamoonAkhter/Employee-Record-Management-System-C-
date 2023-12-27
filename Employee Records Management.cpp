#include<iostream>
#include<cstdio>
using namespace std;

// Define a structure to represent an Employee
struct Employee {
  char name[50];
  int IDs;
  char position[50];
  int salaries;
};

void clearscreen() {
    system("cls");
}

void displayWelcomePage() {
    cout << "*********************************************\n";
    cout << "    Welcome to Employee Record Management    \n";
    cout << "*********************************************\n";
    cout << "\nPlease press any to continue";
    getchar();
    clearscreen();
}

int main() {
    // Declare an array of Employee structure named user1 with a size of 2
    Employee user1[2];

    // Display the welcome page
    displayWelcomePage();

    // Loop to get information for two employees
    for(int i=0; i<2; i++) {
        // Prompt user to enter their name and store it in the 'name' field of the Employee Structure
        cout << "Enter your name: ";
        cin.ignore(); // Ignore new line character from the previous input
        cin.getline(user1[i].name, sizeof(user1[i].name));

        // Prompt the user to enter ID
        cout << "Enter your ID: ";
        cin >> user1[i].IDs;

        //Prompt user to enter position
        cout << "Enter your Position: ";
        cin.ignore();
        cin.getline(user1[i].position, sizeof(user1[i].position));

        // Enter your salary
        cout << "Enter your salary: ";
        cin >> user1[i].salaries;

        clearscreen();
    }

    // Declare a file pointer name fptr and open a file named "Employee.txt" for writing
    FILE *fptr;
    fptr = fopen("Employee.txt","w");

    // Check if the file opening was successful
    if(fptr == NULL) {
        // if the file opening failed
        cout << "The file is failed to open. The program will exit now.";
    }
    else {
        //If the file opening was successful, display a success message
        cout << "The file is created successfully." << endl;

        //Loop through the user1 array and write employee information to the file
        for(int i=0; i<2; i++) {
            fprintf(fptr, "Name: %s\nID: %d\nPosition: %s\nSalary: %d\n\n",
                    user1[i].name, user1[i].IDs, user1[i].position, user1[i].salaries);
        }
        cout << "The information of each employee is stored in a file successfully" << endl;
        fclose(fptr);
        cout << "The file is now closed." << endl << endl;

        cout << "Press any key to exist the program";
        getchar();

    }

    return 0;
}
