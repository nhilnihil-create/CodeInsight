#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n;i++)

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << ((a + b + c) - max(a, max(b, c)) == max(a, max(b, c)) ? "Yes" : "No") << endl;
}