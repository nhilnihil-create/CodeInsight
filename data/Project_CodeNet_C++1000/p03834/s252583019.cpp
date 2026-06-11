#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int main()
{
    string S;
    cin >> S;

    for (int i = 0; i < 19; i++)
    {
        if (i == 5 || i == 13)
            cout << " ";
        else
            cout << S[i];
    }
}