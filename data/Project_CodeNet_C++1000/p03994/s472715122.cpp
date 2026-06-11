#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

string &func(int index,int left,string &s){
	char nowC = s.at(index);

	if(left>='z'-nowC+1 && nowC != 'a')
	{
		left -= ('z'-nowC+1);
		s[index]='a';
	}
	if(index == s.size()-1){
		if(left)left%=26;
		s[index]+=left;
		return s;
	}
	else{
		return func(index+1,left,s);
	}
}

signed main(){
	string s;
	cin>>s;
	lli k;
	cin>>k;
	cout<<func(0,k,s)<<endl;

	return 0;
}