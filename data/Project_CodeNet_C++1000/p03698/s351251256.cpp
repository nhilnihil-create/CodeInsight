#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;

    vector<bool> occured(26);
    for (int i = 0; i < (int)S.size(); i++)
    {
        int c = S.at(i) - 'a';
        if (occured.at(c))
        {
            cout << "no" << endl;
            return 0;
        }
        occured.at(c) = true;
    }
    cout << "yes" << endl;
    return 0;
}
