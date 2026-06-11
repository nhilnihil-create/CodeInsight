#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a=-1e18,b=-1e18,c;
int n,op=1;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(cin>>n;n --> 0;){
		int x;char s[10];cin>>x>>s;x*=op;a+=x;b-=x;c+=x;
		if(x<0)a=max(a,b),b=max(b,c);c=max(b,c);b=max(a,b);
		if(s[0]=='-')op=-1;else op=1;
	}
	cout<<c<<'\n';
	return 0;
}
