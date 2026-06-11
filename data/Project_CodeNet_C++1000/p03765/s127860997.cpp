#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int sum[N],sum1[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s,t;
	int q,i,j,k,l;
	cin>>s>>t>>q;
	s=' '+s;
	t=' '+t;
	for(i=1;i<s.size();i++){
		sum[i]=sum[i-1]+(int)(s[i]-'A'+1);
	}
	for(i=1;i<t.size();i++){
		sum1[i]=sum1[i-1]+(int)(t[i]-'A'+1);
	}
	while(q--){
		cin>>i>>j>>k>>l;
		if((sum[j]-sum[i-1])%3==(sum1[l]-sum1[k-1])%3){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}