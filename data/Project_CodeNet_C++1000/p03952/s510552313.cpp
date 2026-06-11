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
int n, x;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>x;
    if(x==1||x==2*n-1){
        return no,0;
    }
    vector<int> ans(2*n-1);
    ans[n-2]=2*n-1;
    ans[n-1]=x;
    ans[n]=1;
    int k=2*n-2;
    for(int i=n+1;i<2*n-1;i++){
        if(k==x){
            k--;
            ans[i]=k;
            k--;
        }
        else{
            ans[i]=k;
            k--;
        }
    }
    for(int i=0;i<n-2;i++){
        if(k==x){
            k--;
            ans[i]=k;
            k--;
        }
        else{
            ans[i]=k;
            k--;
        }
    }
    yes;
    for(int i=0;i<2*n-1;i++){
        cout<<ans[i]<<"\n";
    }
}

