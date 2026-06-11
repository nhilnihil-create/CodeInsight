#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define show(x) cout<<#x<<"="<<x<<"\n"
using namespace std;

int n,t;
int a[100001];
int dp[100001];
const int inf=999999999;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout<<fixed;
#ifdef LOCAL_DEFINE
    freopen("in", "r", stdin); 
    freopen("out","w",stdout);
#endif
    cin>>n>>t;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    int l=0,r=0;
    int nowmax=0;
    int ans=0;
    for(int r=0;r<n;r++){
    	if(a[r]<a[l]){
    		l=r;
    	}else{
    		if(nowmax<a[r]-a[l]){
    			nowmax=a[r]-a[l];
    			ans=1;
    		}else if(nowmax==a[r]-a[l]){
    			ans++;
    		}
    	}
    }
    cout<<ans<<"\n";
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
