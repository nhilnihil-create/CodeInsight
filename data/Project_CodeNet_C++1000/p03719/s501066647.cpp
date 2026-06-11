#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;
    cin >> a >> b >> c;
    if (c >= a && c <= b)
        cout << "Yes" << endl;
    else
        cout << "No";
    return 0;
}