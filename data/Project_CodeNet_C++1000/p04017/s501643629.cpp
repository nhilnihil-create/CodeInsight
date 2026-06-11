#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=1e5+5;
vector<ll> V;
ll dp[maxn][30];
int pos[maxn];
int main() {
    int n,L,Q;cin>>n;
    for(int i=1;i<=n;i++) cin>>pos[i];cin>>L>>Q;
	pos[n+1]=2e9+5;
	for(int l=1,r=1;l<=n;l++) {
		while(pos[r]-pos[l]<=L) r++;
		dp[l][0]=r-1;
	}
	for(int i=1;i<30;i++) for(int j=1;j<=n;j++)
		dp[j][i]=dp[dp[j][i-1]][i-1];
    for(int i=1;i<30;i++) for(int j=1;j<=n;j++)
    	if(dp[j][i]==0) dp[j][i]=n+1;
    while(Q--){
    	int l,r,ans=0;cin>>l>>r;
    	if(l>r) swap(l,r);
    	for(int i=29;i>=0;i--) {
    		if(dp[l][i]>=r) continue;
    		else ans+=(1<<i),l=dp[l][i];
    	}
   		cout<<ans+1<<endl;
    }
    return 0;
}