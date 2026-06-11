#include <bits/stdc++.h>
using namespace std; void solve(); int main()
{ cin.tie(0); ios::sync_with_stdio(false); solve(); return 0; }
typedef long long ll;
template<class T>bool chmin(T &a, const T &b)
{ if (a<b) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b)
{ if (b<a) { a=b; return true; } return false; }
//----------------------------------------------------------------

ll gcd(ll m, ll n)
{
    if(m>n) swap(m,n);
    if(m==0) return n;
    return gcd(n%m, m);
}

ll lcm(ll a, ll b)
{
    ll g=gcd(a, b);
    ll x=a/g, y=b/g;
    return g*x*y;
}

void solve()
{
    int N;
    cin >> N;

    ll l=1; 
    for(int i=0; i<N; i++)
    {
        ll n;
        cin >> n;
        l=lcm(l, n);
    }
    cout << l << "\n";
}