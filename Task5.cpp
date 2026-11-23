#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file("students.txt");

    char name[20];
    int id;
    float grade;
    char choice;

    do
    {
        cout << "Enter student name: ";
        cin.getline(name, 20);

        cout << "Enter student ID: ";
        cin >> id;

        cout << "Enter student grade: ";
        cin >> grade;

        file << name << "," << id << "," << grade << "$" << endl;

        cout << "Do you want to add another student? (y/n): ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');

    file.close();

    cout << "Student records saved successfully.";

    return 0;
}