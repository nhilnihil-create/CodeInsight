#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define mp make_pair
using namespace std;
ll used[114514];	vector<ll> pat[114514];
int main(){
	ll n,m;
	cin>>n>>m;
	deque<ll> ham;
	for(int i=0;i<m;i++){
		ll ta,tb;
		cin>>ta>>tb;
		if(i==0){
			ham.pb(ta);used[ta]++;
			ham.pb(tb);used[tb]++;
		}
		pat[ta].pb(tb);
		pat[tb].pb(ta);
	}
	ll f = 0;
	while(f==0){
		f=1;
		ll cur = ham[0];
		for(ll j=0;j<pat[cur].size();j++){
			if( used[ pat[cur][j]  ] == 0 && f==1){
				ham.push_front( pat[cur][j] );
				used[ pat[cur][j] ] = 1;
				f = 0;
			}
		}
		cur = ham[ham.size()-1];
		for(ll j=0;j<pat[cur].size();j++){
			if( used[ pat[cur][j]  ] == 0 && f==1){
				ham.push_back( pat[cur][j] );
				used[ pat[cur][j] ] = 1;
				f = 0;
			}
		}
		if(f==1){
			cout<<ham.size()<<endl;
			for(int i=0;i<ham.size();i++){
				cout<<ham[i]<<" ";
			}
			cout<<endl;
			return 0;
		}
	}
	return 0;
}