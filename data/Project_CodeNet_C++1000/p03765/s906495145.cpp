#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define LINF 1000000000000000007LL
#define ll long long
using namespace std;
int ssum[114514],tsum[114514];
signed main(){
	string s,t;
	cin>>s>>t;
	int n;
	cin>>n;
	vector<int> sl,sr,tl,tr;
	for(int i=1;i<=s.size();i++){
		if( s[i-1] == 'A' ) ssum[i] = ssum[i-1] + 1;
		else ssum[i] = ssum[i-1] + 2;
	}
	for(int i=1;i<=t.size();i++){
		if( t[i-1] == 'A' ) tsum[i] = tsum[i-1] + 1;
		else tsum[i] = tsum[i-1] + 2;
	}
	for(int i=0;i<n;i++){
		int x,y,z,w;
		cin>>x>>y>>z>>w;
		sl.pb(x);sr.pb(y);tl.pb(z);tr.pb(w);
	}
	for(int i=0;i<n;i++){
		int sval = ssum[sr[i]] - ssum[sl[i]-1];
		int tval = tsum[tr[i]] - tsum[tl[i]-1];
		if( abs(sval-tval) % 3 == 0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}