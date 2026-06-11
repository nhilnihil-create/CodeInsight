/*
    Author:zeke
    
    pass System Test!
    GET AC!!
*/
#include <iostream>
#include <queue>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <map>
#include <iomanip>
#include <utility>
#include <stack>
#include <bitset>
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rep3(var, min, max) for (ll(var) = (min); (var) < (max); ++(var))
#define repi3(var, min, max) for (ll(var) = (max)-1; (var) + 1 > (min); --(var))
#define Mp(a, b) make_pair((a), (b))
#define F first
#define S second
#define Icin(s) \
    ll(s);      \
    cin >> (s);
#define Scin(s) \
    ll(s);      \
    cin >> (s);
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<P> VP;
ll mod = 1e9 + 7;
ll MOD = 1e9 + 7;
ll INF = 1e18;
ll modpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    else if (b % 2 == 0)
    {
        ll d = modpow(a, b / 2) % MOD;
        return (d * d) % MOD;
    }
    else
    {
        return (a * modpow(a, b - 1)) % MOD;
    }
}

const int MAX_N = 100010;

ll fact[MAX_N], finv[MAX_N];
ll comb(int n, int r)
{
    if (n < r || r < 0)
        return 0;
    return fact[n] * finv[n - r] % MOD * finv[r] % MOD;
}

void calc(int n)
{
    fact[0] = finv[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        finv[i] = modpow(fact[i], MOD - 2);
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    V vec1(n);
    rep(i, n) cin >> vec1[i];
    V vec2(n);
    rep(i, n) cin >> vec2[i];
    V reg(n, -1);
    reg[0] = vec1[0];
    rep3(i,1,n){
        if(vec1[i]!=vec1[i-1]){
            reg[i] = vec1[i];
        }
    }
    if(reg[n-1]!=-1&&reg[n-1]!=vec2[n-1]){
        cout<<0<<endl;
        return 0;
    }
    reg[n-1]=vec2[n-1];
  //  rep(i,n)cout<<reg[i]<<" ";
  //  cout<<endl;
    for (int i = n - 2; i >= 0;i--){
        if(reg[i]!=-1){
            if(vec2[i]!=vec2[i+1]){
                if(reg[i]!=vec2[i]){
                    cout << 0 << endl;
                    return 0;
                }
            }else{
                if(vec2[i]<reg[i]){
                    cout << 0 << endl;
                    return 0;
                }
            }
        }else{
            if(vec2[i]!=vec2[i+1]){
                reg[i] = vec2[i];
            }
        }
    }
  //  rep(i,n)cout<<reg[i]<<" ";
  //  cout<<endl;
    ll sum = 1;
    rep(i,n){
        if(reg[i]==-1){
            sum *= min(vec1[i], vec2[i]);
            sum %= MOD;
        }
    }
    cout << sum << endl;
}
