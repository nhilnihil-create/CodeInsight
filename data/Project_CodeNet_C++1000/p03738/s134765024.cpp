#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    if (a.size() < b.size()) cout << "LESS";
    else if (a.size() > b.size()) cout << "GREATER";
    else {
        bool equal = true;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] > b[i])
            {
                equal = false;
                cout << "GREATER";
                break;
            }
            else if (a[i] < b[i])
            {
                equal = false;
                cout << "LESS";
                break;
            }
        }
        if (equal == true) cout << "EQUAL";
    }
}