#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair 
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	//input
	string s; cin>>s;

	//solve
	if(sz(s)<4) cout<<"No";
	else{
		string t="";
		rep(i,4){
			t+=s[i];
		}
		if(t=="YAKI") cout<<"Yes";
		else cout<<"No";
	}
}