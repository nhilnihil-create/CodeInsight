#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int N; cin >> N;
    vector<ll> x(N); for(int i=0;i<N;i++) cin >> x[i];
    ll L; cin >> L;

    ll tmp=0;
    int y[N];
    int j=0;
    for(int i=0;i<N;i++){
        int ind=upper_bound(x.begin(),x.end(),x[i]+L)-x.begin();
        if(ind>=N) ind=N;
        y[i]=ind-1;
    }

    int dp[30][N];
    for(int i=0;i<N;i++){
        dp[0][i]=y[i];
    }
    for(int i=0;i<29;i++){
        for(int j=0;j<N;j++){
            dp[i+1][j]=dp[i][dp[i][j]];
        }
    }
  
    int Q; cin >> Q;
    while(Q--){
        int a,b; cin >> a >> b;
        a--; b--;
        if(b<a) swap(a,b);
        ll ans=0;
        for(int i=29;i>=0;i--){
            if(dp[i][a]<b){
                a=dp[i][a];
                ans+=(1<<i);
            }
        }
        if(a==b) cout << ans << endl;
        else cout << ans+1 << endl;
    }
}