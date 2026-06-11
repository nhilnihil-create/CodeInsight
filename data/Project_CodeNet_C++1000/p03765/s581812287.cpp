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

#define P pair<lli,lli>

lli sumA[100100],sumB[100100];

lli conv(char A){
	if(A=='A')return 2;
	else return 1;
}

signed main(){

	string s,t;
	cin>>s>>t;

	sumA[0]=0,sumB[0]=0;
	REP(i,0,s.size()){
		sumA[i+1] = sumA[i]+conv(s.at(i));
	}
	REP(i,0,t.size()){
		sumB[i+1] = sumB[i]+conv(t.at(i));
	}

	lli q;
	cin>>q;

	REP(i,0,q){
		lli a,b,c,d;
		cin>>a>>b>>c>>d;
		a--,b--,c--,d--;

		lli sB = sumA[b+1]-sumA[a];
		lli tB = sumB[d+1]-sumB[c];

		if(DEBUG)cout<<"sB="<<sB<<"tB="<<tB<<endl;

		if(sB%3 == tB%3)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}


	return 0;
}