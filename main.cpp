#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Student
{
public:
    int rollNo;
    string name;
    float marks;

    void input()
    {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;

        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display()
    {
        cout << "\nRoll Number: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks;
        cout << "\n-----------------------";
    }
};


void addStudent()
{
    Student s;

    ofstream file("students.txt", ios::app);

    s.input();

    file << s.rollNo << endl;
    file << s.name << endl;
    file << s.marks << endl;

    file.close();

    cout << "\nStudent added successfully!\n";
}


void displayStudents()
{
    Student s;

    ifstream file("students.txt");

    if(!file)
    {
        cout << "\nNo records found!";
        return;
    }


    while(file >> s.rollNo)
    {
        file.ignore();

        getline(file, s.name);

        file >> s.marks;

        s.display();
    }

    file.close();
}


void searchStudent()
{
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to search: ";
    cin >> roll;


    Student s;

    ifstream file("students.txt");


    while(file >> s.rollNo)
    {
        file.ignore();

        getline(file, s.name);

        file >> s.marks;


        if(s.rollNo == roll)
        {
            s.display();
            found = true;
            break;
        }
    }


    file.close();


    if(!found)
    {
        cout << "\nStudent not found!";
    }
}



void deleteStudent()
{
    int roll;
    bool deleted = false;


    cout << "\nEnter Roll Number to delete: ";
    cin >> roll;


    Student s;


    ifstream file("students.txt");

    ofstream temp("temp.txt");


    while(file >> s.rollNo)
    {
        file.ignore();

        getline(file, s.name);

        file >> s.marks;


        if(s.rollNo != roll)
        {
            temp << s.rollNo << endl;
            temp << s.name << endl;
            temp << s.marks << endl;
        }
        else
        {
            deleted = true;
        }
    }


    file.close();
    temp.close();


    remove("students.txt");

    rename("temp.txt","students.txt");


    if(deleted)
        cout << "\nStudent deleted successfully!";
    else
        cout << "\nStudent not found!";
}



int main()
{

    int choice;


    do
    {

        cout << "\n===== Student Record Management =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Delete Student";
        cout << "\n5. Exit";


        cout << "\n\nEnter your choice: ";
        cin >> choice;



        switch(choice)
        {

        case 1:
            addStudent();
            break;


        case 2:
            displayStudents();
            break;


        case 3:
            searchStudent();
            break;


        case 4:
            deleteStudent();
            break;


        case 5:
            cout << "\nExiting program...";
            break;


        default:
            cout << "\nInvalid choice!";
        }


    }
    while(choice != 5);


    return 0;
}