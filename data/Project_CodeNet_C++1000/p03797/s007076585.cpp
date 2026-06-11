#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    ll hc = m / 2, gcc = 0;
    gcc += min(hc, n);
    m -= gcc * 2;
    gcc += m / 4;
    cout << gcc << endl;
}