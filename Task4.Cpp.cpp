#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Person
{
    string name;
    int age;
};

int main()
{
    int n;

    cout << "Enter number of persons: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of persons.";
        return 1;
    }

    ofstream outfile("persons.txt");

    if (!outfile.is_open())
    {
        cout << "Error opening persons file.";
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        Person p;

        cout << "Enter name of person " << i + 1 << ": ";
        getline(cin >> ws, p.name);

        cout << "Enter age: ";
        cin >> p.age;

        outfile << p.name << endl;
        outfile << p.age << endl;
    }

    outfile.close();

    vector<Person> persons;

    ifstream infile("persons.txt");

    if (!infile.is_open())
    {
        cout << "Error reading persons file.";
        return 1;
    }

    Person p;

    while (getline(infile, p.name))
    {
        if (!(infile >> p.age))
        {
            break;
        }

        infile.ignore(10000, '\n');

        persons.push_back(p);
    }

    infile.close();

    if (persons.empty())
    {
        cout << "No persons found.";
        return 1;
    }

    Person youngest = persons[0];
    Person oldest = persons[0];

    for (int i = 1; i < persons.size(); i++)
    {
        if (persons[i].age < youngest.age)
        {
            youngest = persons[i];
        }

        if (persons[i].age > oldest.age)
        {
            oldest = persons[i];
        }
    }

    ofstream results("results.txt");

    if (!results.is_open())
    {
        cout << "Error opening results file.";
        return 1;
    }

    results << "Youngest Person:" << endl;
    results << "Name: " << youngest.name << endl;
    results << "Age: " << youngest.age << endl;

    results << endl;

    results << "Oldest Person:" << endl;
    results << "Name: " << oldest.name << endl;
    results << "Age: " << oldest.age << endl;

    results.close();

    cout << "Data saved successfully." << endl;
    cout << "Check results.txt for the results.";

    return 0;
}
