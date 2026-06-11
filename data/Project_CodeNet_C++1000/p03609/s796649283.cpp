#include <bits/stdc++.h>

using namespace std;

int main()
{
    int X, T; cin >> X >> T;
    X -= min(X, T);
    cout << X << "\n";
}