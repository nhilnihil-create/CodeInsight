//#include <tourist>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <tuple>
#include <deque>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <utility>
#include <complex>
#include <functional>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = (1 << 28);
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
//setprecision(15)有効数字15桁
//-std=c++14
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
struct edge {
    int to, cost;
};
ll n, a, b;
vector<ll> v;
const ll M = pow(10, 9) + 7;

vector<ll> fac(10000001);  //n!(mod M)
vector<ll> ifac(10000001); //k!^{M-2} (mod M)
ll mpow(ll x, ll n)
{ //x^n(mod M)
    ll ans = 1;
    while (n != 0)
    {
        if (n & 1)
            ans = ans * x % M;
        x = x * x % M;
        n = n >> 1;
    }
    return ans;
}
//conbination
ll comb(ll a, ll b)
{ //aCb(mod M)
    if (a == 0 && b == 0)
        return 1;
    if (a < b || a < 0)
        return 0;
    ll tmp = ifac[a - b] * ifac[b] % M;
    return tmp * fac[a] % M;
}
ll nCr(ll n, ll m) {
    // cout << n << " - " << m << endl;
    m = min(m, n-m);
    if (m == 0) return 1;
    ll num = 1, dem = 1;
    for(ll i = 1; i <= m; i++) {
        num = (num*(n+1-i));
        num = num / i;
    }
    return num;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    fac[0] = 1;
    ifac[0] = 1;
    for (ll i = 0; i < 1000000; i++)
    {
        fac[i + 1] = fac[i] * (i + 1) % M;              // n!(mod M)
        ifac[i + 1] = ifac[i] * mpow(i + 1, M - 2) % M; // k!^{M-2} (mod M)
    }
    cin >> n>>a>>b;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(ALL(v));
    ll ans=0;
    for(int i=0;i<a;i++){
        ans+=v[n-i-1];
    }
    ll incount=1;
    ll outcount=0;
    for(int i=0;i<a-1;i++){
        if(v[n-1-i]==v[n-2-i]){
            incount++;
        }
        else{
            incount=1;
        }
    }
    for(int i=a-1;i<n;i++){
        if(v[n-1-i]==v[n-2-i]){
            outcount++;
        }
        else{
            break;
        }
    }
    cout<<setprecision(22)<<double(ans)/double(a)<<"\n";
    if(incount==a){
        ll count=0;
        for(ll i=a;i<=min(a+outcount,b);i++){
            //count+=comb(outcount+incount,i);
            //cout<<count<<"\n";
            //cout<<outcount+incount<<" "<<i<<"\n";
            //cout<<a+outcount<<" "<<i<<"\n";
            count+=nCr(outcount+incount,i);
        }
        cout<<count<<"\n";
    }
    else{
    //cout<<outcount<<" "<<incount<<"\n";
    cout<<nCr(outcount+incount,incount)<<"\n";
    }
}

