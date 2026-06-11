#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ll inf=1ll<<60,mod=1000000007;

int main()
{
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i,j,k,n,ans=1,t;
	string a,b;
	cin>>n>>a>>b;
	for (i=0;i<a.size();i++){
		if (i==0){
			if (a[i]==b[i]){
				ans*=3;
			}
			else {
				i++;
				ans*=6;
			}
		}
		else {
			if (a[i]==b[i]){
				if (a[i-1]==b[i-1]){
					ans=(ans*2)%mod;
				}
			}
			else {
				if (a[i-1]!=b[i-1]) {
					ans=(ans*3)%mod;
				}
				else {
					ans=(ans*2)%mod;
				}
				i++;
			}
		} 
	}
	cout<<ans;
	return 0;
}