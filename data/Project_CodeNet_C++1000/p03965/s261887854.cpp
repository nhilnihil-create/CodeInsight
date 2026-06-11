#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    string s;
    cin >> s;
    ll cnt = 0;
    rep(i, s.length())
    {
        if (s[i] == 'p')
            cnt++;
    }
    cout << s.length() / 2 - cnt << endl;
}