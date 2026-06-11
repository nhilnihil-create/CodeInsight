#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cstring>
#include<cmath>
#include <numeric>
#include<queue>
#include<climits>
#include<cstdio>
#include<map>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
//#define INF ((LLONG_MAX) / (2))
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;
typedef pair<ll,int> LL_IP;
typedef pair<ll,ll> LL_LLP;
#define INF 1000000007
#define MAX_H 100005

int main(){

    ll n,t,mini = INF,maxi_profit = -1,ans = 0;
    cin >> n >> t;
    vector<ll> a(n);
    vector<ll> profit(n);

    REP(i,n){
        cin >> a[i];
        mini = min(mini,a[i]);/*これまでに見た値段の最小値を求める*/
        profit[i] = a[i] - mini;
        maxi_profit = max(maxi_profit,profit[i]);
    }

    REP(i,n){
        if(profit[i] == maxi_profit){
            ans++;
        }
    }
    cout << ans << endl;
   
}
