#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n;
vector < int > v,ans;
main () {
	cin>>n;
	
	while (n) {
		if (n%2==1) {
			n--;
			n/=2;
			v.pb(1);
		}
			else {
			n--;
			v.pb(0);
		}
	}
	
	reverse(v.begin(),v.end());
	
	for (int i=0; i<v.size(); i++) {
		if (v[i]) ans.pb(i+1);
			else {
			reverse(ans.begin(),ans.end());
			ans.pb(i+1);
			reverse(ans.begin(),ans.end());
		}		
	}
	
	for (int i=0; i<v.size(); i++)
		ans.pb(i+1);	

	cout<<ans.size()<<endl;
	for (int i=0; i<ans.size(); i++)
		cout<<ans[i]<<" ";	
}