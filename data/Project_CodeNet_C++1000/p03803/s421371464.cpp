#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    if(a==b)
    {
        cout << "Draw\n";
    }
    else if(b==1 || (a!=1 && a<b))
    {
        cout << "Bob\n";
    }
    else
    {
        cout << "Alice\n";
    }

    return 0;
}