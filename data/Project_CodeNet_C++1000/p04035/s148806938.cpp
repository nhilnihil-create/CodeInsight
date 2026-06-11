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
ll n, l;
vector<ll> a;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>l;
    ll center=-1;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        a.push_back(temp);
    }
    for (int i = 0; i < n-1; i++)
    {
        if(a[i]+a[i+1]>=l){
            center=i;
        }
    }
    if(center==-1){
        return cout<<"Impossible"<<"\n",0;
    }
    cout<<"Possible"<<"\n";
    for(int i=0;i<center;i++){
        cout<<i+1<<"\n";
    }
    for(int i=n-2;i>=center;i--){
        cout<<i+1<<"\n";
    }
}

