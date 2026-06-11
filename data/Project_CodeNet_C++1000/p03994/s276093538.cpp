#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(lli i=s;i<n;i++)
#define RREP(i,s,n) for(lli i=s;i>=n;i--)
#define MOD 1000000007
#define NUM 2520
#define DEBUG 1
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define INF (1LL<<50)

signed main(){

	string s;
	cin>>s;

	lli k;
	cin>>k;

	REP(i,0,s.size()){
		if(s.at(i)=='a')continue;
		lli use = 'z'-s.at(i)+1;
		if(use<=k){
			k-=use;
			s[i]='a';
		}
	}

	if(k>0){
		s[s.size()-1] += k%26;
	}
	cout<<s<<endl;

	return 0;
}