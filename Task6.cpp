#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
    ofstream file("grades.txt");

    int grades[5];

    cout << "Enter 5 grades:" << endl;

    for (int i = 0; i < 5; i++)
    {
        cin >> grades[i];
        file << grades[i] << endl;
    }

    file.close();

    cout << "\nGrades in file:" << endl;

    ifstream readFile("grades.txt");

    int grade;

    while (readFile >> grade)
    {
        cout << grade << endl;
    }

    readFile.close();

    int deleteGrade;

    cout << "\nEnter grade to delete: ";
    cin >> deleteGrade;

    ifstream inputFile("grades.txt");
    ofstream tempFile("temp.txt");

    bool found = false;

    while (inputFile >> grade)
    {
        if (grade == deleteGrade && !found)
        {
            found = true;
            continue;
        }

        tempFile << grade << endl;
    }

    inputFile.close();
    tempFile.close();

    if (found)
    {
        remove("grades.txt");
        rename("temp.txt", "grades.txt");

        cout << "Grade deleted successfully!" << endl;
    }
    else
    {
        remove("temp.txt");
        cout << "Grade not found!" << endl;
    }

    cout << "\nGrades after deletion:" << endl;

    ifstream finalFile("grades.txt");

    while (finalFile >> grade)
    {
        cout << grade << endl;
    }

    finalFile.close();

    return 0;
}