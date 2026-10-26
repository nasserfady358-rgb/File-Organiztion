#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string name;
    int id;
    float grade;

    cout << "Enter full name: ";
    getline(cin, name);

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter grade: ";
    cin >> grade;

    ofstream myfile("Student.txt");

    if (myfile.is_open())
    {
        myfile << "Name: " << name << endl;
        myfile << "ID: " << id << endl;
        myfile << "Grade: " << grade << endl;

        myfile.close();

        cout << "Student data saved successfully.";
    }
    else
    {
        cout << "Error opening file.";
    }

    return 0;
}
