#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e6+5;
int main() {
	map<int,int> M;
	int n,T;cin>>n>>T;
	std::vector<int> price(n+1);
	for(int i=1;i<=n;i++) cin>>price[i];
	int mn=price[1],mx=0;
	for(int i=2;i<=n;i++) {
		mn=min(mn,price[i]);
		mx=max(price[i]-mn,mx);
	}
	if(mx==0) return 0*puts("0");
	int ans=0;mn=price[1];
	for(int i=2;i<=n;i++) {
		mn=min(mn,price[i]);
		if(price[i]-mn==mx) ans++;
	}
	cout<<ans<<endl;
    return 0;
}