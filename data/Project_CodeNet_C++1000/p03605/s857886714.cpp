#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    int n, a;
    cin >> n;
    if (n % 10 == 9 || n / 10 % 10 == 9)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}