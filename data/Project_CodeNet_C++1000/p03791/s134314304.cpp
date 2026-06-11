#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
#define mod (int)(1e9+7)
using namespace std;

int n,a[100005];
signed main() {
	cin>>n;
	rep(i,n)cin>>a[i];
	stack<int>st;
	int k=0,ans=1;
	rep(i,n){
		if(a[i]<k*2+1){
			ans*=(k+1);
			ans%=mod;
		}else {
			st.push(a[i]);
			k++;
		}
	}
	for(int i=1;i<=st.size();i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans<<endl;
}
