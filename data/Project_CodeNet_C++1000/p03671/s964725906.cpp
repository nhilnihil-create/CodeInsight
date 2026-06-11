#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    cout << min(a+b,min(b+c,c+a)) << endl;
}