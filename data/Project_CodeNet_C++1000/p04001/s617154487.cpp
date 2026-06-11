#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define re return
#define all(a) a.begin(),a.end()
#define int long long
using namespace std;
signed main()
{
	string s;
	cin>>s;
	int ans=0;//cout<<"sz(s)="<<sz(s)<<"\n\n";
	for (int i=0;i<sz(s);i++){
		int num=s[i]-'0',x=0;
		//cout<<"i="<<i<<'\n';
		for (int j=1;j<=sz(s)-i;j++){
			if (j==sz(s)-i){
				x+=(num*( 1<<i ));//cout<<"num*"<<(1<<i)<<' ';
			}
			else {
				x+=(num*( (1<<(sz(s)-1-j)) ));//cout<<"num*"<<(1<<(sz(s)-1-j))<<' ';
			}
			//cout<<"num="<<num<<'\n';
			num*=10;
		}
		ans+=x;
		//cout<<"x="<<x<<'\n';
	}
	//cout<<"ans="<<ans;
	cout<<ans;
	re 0;
}