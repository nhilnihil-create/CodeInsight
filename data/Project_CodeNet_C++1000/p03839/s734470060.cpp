#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long int ll;
ll s[100010];//普通の累積和
ll t[100010];//正の項についての累積和
int main(){
	int n,k; cin >>n>>k;
	vector<ll> a(n);
	for(int i=0;i<n;i++){
		cin >>a[i];
	}
	for(int i=0;i<n;i++){
		s[i+1]=s[i]+a[i];
		t[i+1]=t[i]+max((ll)0,a[i]);
	}
	ll ans=s[n];
	for(int i=0;i<=n-k;i++){
		ll left=t[i];
		ll right=t[n]-t[i+k];
		ans=max(left+right+(s[i+k]-s[i]),ans);//区間を黒に固定する場合
		ans=max(left+right,ans);//区間を白に固定する場合
	}
	cout << ans << endl;
}