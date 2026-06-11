#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;
ll MOD=1000000007;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> a(m,0),b(n,0);
    int ans=inf;
    vector<vector<int>> e(n,vector<int>(m));
    rep(i,n){
        rep(j,m) {cin >> e[i][j];
        e[i][j]--;}
    }
    rep(i,m){
        int k=0;
        vector<int> c(m,0);
        rep(j,n){
            c[e[j][b[j]]]++;
            k=max(k,c[e[j][b[j]]]);
        }
        int u;
        rep(j,m){
            if (c[j]==k) u=j;
        }
        ans=min(ans,k);
        a[u]=-1;
        if (i==m-1) break;
        rep(i,n){
            while(true){
                if (a[e[i][b[i]]]!=-1) break;
                b[i]++;
            }
        }
    }   
    cout << ans << endl;                 
}
