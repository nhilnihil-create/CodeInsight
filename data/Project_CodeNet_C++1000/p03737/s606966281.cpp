#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;

ll mod = 1000000007;
ll ans = 1<<29;

int main() {
    string s,t,u;
    cin >> s>>t >>u;
    char dif = 'A' -'a';
    char S = s[0]+ dif;
    char T = t[0]+ dif;
    char U = u[0]+ dif;
    cout << S << T << U  <<endl;
        }