#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define showmap(is, js, x) {rep(i, is){rep(j, js){cout << x[i][j] << " ";}cout << endl;}}
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    int n, x;
    cin >> n >> x;
    vector<ll> a;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}

    ll ans = 0;
    if (a[0] > x) {ans += a[0]-x; a[0] = x;}
    ll sum = a[0];
    for (int i = 1; i < n; i++)
    {
        sum += a[i];
        if (sum > x) {
            ans += sum-x;
            a[i] -= sum-x;
            sum -= sum-x;
        }
        sum -= a[i-1];
    }
    
    cout << ans << endl;

}
