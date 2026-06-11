#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int a[50],b[50],c[50];
int n,ma,mb;
int dp[50][405][405];
int f(int i,int j,int k){
    if(i == n){
        if(ma * k == mb * j && j != 0 && k != 0){
            return 0;
        }
        return 1e9;
    }
    if(dp[i][j][k] != -1)return dp[i][j][k];
    int &ans = dp[i][j][k];
    ans = 1e9;
    ans = min(ans,f(i + 1,j,k));
    ans = min(ans,f(i + 1,j + a[i],k + b[i]) + c[i]);
    return ans;

}
int main(){/*
    freopen("in","r",stdin);
    freopen("out","w",stdout);*/
    fast;
    cls(dp,-1);
    cin >> n >> ma >> mb;
    fore(i,0,n)
        cin >> a[i] >> b[i] >> c[i];
    int ans = f(0,0,0);
    if(ans > 1e5)
        cout << "-1\n";
    else
        cout << ans << '\n';
    return 0;   
}