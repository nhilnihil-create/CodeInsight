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
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
struct edge {
    int to, cost;
};
int n;
vector<ll> t, a;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    vector<ll> minh(n);
    for (int i = 0; i < n; i++)
    {
        ll tempt;
        cin >> tempt;
        t.push_back(tempt);
    }
    for (int i = 0; i < n; i++)
    {
        ll tempa;
        cin >>tempa;
        a.push_back(tempa);
        minh[i]=min(t[i],tempa);
    }
    if(n==1){
        if(a[0]!=t[0])return cout<<0<<"\n",0;
    }
    vector<bool> used(n,false);
    used[0]=true;
    used[n-1]=true;
    for(int i=0;i<n-1;i++){
        if(t[i]<t[i+1]){
            if(used[i+1]==true&&a[i+1]<t[i+1])return cout<<0<<"\n",0;
            used[i+1]=true;
        }
    }
    for(int i=n-1;i>0;i--){
        if(a[i]<a[i-1]){
            if(a[i-1]>t[i-1]) return cout<<0<<"\n",0;
            used[i-1]=true;
        }
    }
    ll ans=1;
    for(int i=0;i<n;i++){
        if(!used[i]){
            ans*=minh[i];
            ans%=MOD;
        }
    }
    cout << ans << "\n";
}
