#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string text;

    ofstream outfile("welcome.txt");

    if (!outfile.is_open())
    {
        cout << "Error opening file.";
        return 1;
    }

    outfile << "Hello Everybody";
    outfile.close();

    ifstream infile("welcome.txt");

    if (!infile.is_open())
    {
        cout << "Error reading file.";
        return 1;
    }

    getline(infile, text);
    infile.close();

    size_t pos = text.find("body");

    if (pos != string::npos)
    {
        text.replace(pos, 4, "one");
    }

    ofstream result("welcome.txt");

    if (result.is_open())
    {
        result << text;
        result.close();

        cout << "File updated successfully." << endl;
        cout << text;
    }
    else
    {
        cout << "Error updating file.";
    }

    return 0;
}
