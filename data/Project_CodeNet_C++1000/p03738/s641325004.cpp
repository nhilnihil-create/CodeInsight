#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int main(void)
{
    string a, b;
    cin >> a >> b;
    if (a.length() > b.length())
        cout << "GREATER" << endl;
    else if (b.length() > a.length())
        cout << "LESS" << endl;
    else
    {
        int i = 0;
        while (i < a.length() && a[i] == b[i])
            i++;
        if (i == a.length())
            cout << "EQUAL" << endl;
        else if (a[i] > b[i])
            cout << "GREATER" << endl;
        else if (b[i] > a[i])
            cout << "LESS" << endl;
    }
}
