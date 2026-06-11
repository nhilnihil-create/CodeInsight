#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
//const int PI = acos(-1);
int main(){
	int n;cin>>n;
	vl a(n);
	rep(i,n)cin>>a[i];
	sort(been(a));
	int ans =1;
	ll sum[n];
	sum[0]=a[0];
	rep(i,n){
		if(i==0)continue;
		sum[i]=sum[i-1]+a[i];
		if(sum[i-1]*2<a[i])ans=0;
		ans++;
	}
	cout<<ans<<endl;
}