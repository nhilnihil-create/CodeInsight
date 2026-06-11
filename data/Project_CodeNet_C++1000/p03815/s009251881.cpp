#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(), (a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int, int> P;
typedef long long ll;

int main()
{
    ll x;
    cin >> x;

    ll kakeru = x/11;
    ll amari = x%11;

    if(amari >6) amari = 2;
    else if(amari > 0) amari = 1;
    else amari = 0;

    cout << kakeru * 2 + amari << endl;
}