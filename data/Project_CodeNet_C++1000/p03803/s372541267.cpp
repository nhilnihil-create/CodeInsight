#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define inf 1000000100

int main()
{
    int a, b;
    cin >> a >> b;
    if(a!= 1 && b!= 1)
    {
        if(a > b)
        {
            cout << "Alice" << endl;
        }
        else if (a < b)
        {
            cout << "Bob" << endl;
        }
        else
        {
            cout << "Draw" << endl;
        }
    }
    else
    {
        if(a == 1 && b != 1)
        {
            cout << "Alice" << endl;
        }
        else if (b == 1 && a != 1)
        {
            cout << "Bob" << endl;
        }
        else if (a == 1 && b == 1)
        {
            cout << "Draw" << endl;
        }
    }
}