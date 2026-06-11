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
ll n, w, w1;
vector<vector<ll> > v(4);
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>w;
    ll tempv;
    cin>>w1>>tempv;
    v[0].push_back(tempv);
    for (int i = 1; i < n; i++)
    {
        int tempw, tempv;
        cin >> tempw>>tempv;
        v[tempw-w1].push_back(tempv);
    }
    for(int i=0;i<4;i++){
        sort(ALL(v[i]),greater<ll>());
    }
    ll ans = 0;
    vector<vector<ll> > sum(4);
    for(int i=0;i<4;i++){
        ll sumv=0;
        sum[i].push_back(0);
        for(int j=0;j<v[i].size();j++){
            sumv+=v[i][j];
            sum[i].push_back(sumv);
            //cout<<sumv<<"\n";
        }
    }
    for(int i=0;i<sum[0].size();i++){
        for(int j=0;j<sum[1].size();j++){
            for(int k=0;k<sum[2].size();k++){
                for(int l=0;l<sum[3].size();l++){
                    //cout<<j+k*2+l*3+(i+j+k+l)*w1<<"\n";
                    if(j+k*2+l*3+(i+j+k+l)*w1<=w){
                        ans=max(ans,sum[0][i]+sum[1][j]+sum[2][k]+sum[3][l]);
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}
