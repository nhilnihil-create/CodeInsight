#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
string alp="abcdefghijklmnopqrstuvwxyz";

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i,N){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int lb=-1,ub=N;
    vector<vector<bool>> dp(N+1,vector<bool>(K,false));
    while(ub-lb>1){
        int mid=(lb+ub)/2;
        rep(i,N+1){
            rep(j,K){
                dp[i][j]=false;
            }
        }
        dp[0][0]=true;
        rep(i,N){
            rep(j,K){
                dp[i+1][j]=dp[i+1][j]||dp[i][j];
                if (j>=a[i]&&dp[i][j-a[i]]&&i!=mid){
                    dp[i+1][j]=dp[i][j-a[i]];
                }
            }
        }
        bool b=false;
        rep(i,min(K,a[mid])){
            if (dp[N][K-1-i]){
                b=true;
                break;
            }
        }
        if (b){
            ub=mid;
        }
        else {
            lb=mid;
        }
    }
    cout << ub << endl;
}