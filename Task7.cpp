#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string names[4] = {
        "Hadeer Mahmoud",
        "Youssef Ali",
        "Ahmed Mostafa",
        "Esraa Ebrahim"
    };

    sort(names, names + 4);

    cout << "Names in Ascending Order:" << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << names[i] << endl;
    }

    return 0;
}