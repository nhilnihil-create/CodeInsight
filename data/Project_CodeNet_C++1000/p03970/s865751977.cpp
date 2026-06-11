#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007

signed main(){

	string ans ="CODEFESTIVAL2016";
	string s;
	cin>>s;

	lli cnt=0;
	REP(i,0,16){
		if(s.at(i)!=ans.at(i))cnt++;
	}
	cout<<cnt<<endl;

	return 0;
}