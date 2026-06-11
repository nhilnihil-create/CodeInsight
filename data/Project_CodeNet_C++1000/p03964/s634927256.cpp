#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int main()
{
    int n; cin >> n;
    vector<ll> t(n);
    vector<ll> a(n);
    rep(i,n)
    {
        cin >> t[i] >> a[i];
    }
    ll taka = 1;
    ll ao = 1;
    ll ltaka;
    ll lao;
    rep(i,n)
    {
        taka = max((taka - 1) / t[i] + 1, (ao - 1) / a[i] + 1)*t[i];
        ao = max((taka - 1) / t[i] + 1, (ao - 1) / a[i] + 1)*a[i];
    }
    cout << taka+ao << endl;
}