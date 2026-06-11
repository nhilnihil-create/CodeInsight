#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int k;
	cin>>s>>k;
	rep(i,0,s.size()){
		if(s[i]=='a')continue;
		if('a'+26-s[i]<=k){
			k-='a'+26-s[i];
			s[i]='a';
		}
	}
	k%=26;
	s[s.size()-1]+=k;
	cout<<s<<'\n';
	RE 0;
}

