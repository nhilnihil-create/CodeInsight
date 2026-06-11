#include <bits/stdc++.h>
#define int long long
#define inf (int)(3e18)
#define mod (int)(1e9+7)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int a[7],b[7];
signed main(){
	rep(i,7)cin>>a[i];
	rep(i,7)b[i]=a[i];
	int ans=a[1],ans2=a[1];
	if(a[0]&&a[3]&&a[4]){
		ans+=3;a[0]--;a[3]--;a[4]--;
		ans+=a[0]/2*2+a[3]/2*2+a[4]/2*2;
	}
	ans2+=b[0]/2*2+b[3]/2*2+b[4]/2*2;
	cout<<max(ans,ans2)<<endl;
}
