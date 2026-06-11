#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define chmin(a,b) if((a)>(b)) (a)=(b);
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define pb push_back
#define pf push_front
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const long long INF = 1e18+10;

/*--------------------------------------------------------------------*/

signed main(){
	int n;
	cin>>n;
	vi cnt(9,0);
	rep(_,n){
		int a;cin>>a;
		if(a>=3200){
			a=3200;
		}
		cnt[a/400]++;
	}
	int ans=0;
	rep(i,8) if(cnt[i]>0)ans++;

	cout<<max(ans,1)<<' '<<ans+cnt[8]<<endl;
	


	return 0;
}

