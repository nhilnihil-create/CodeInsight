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

signed main(){

	string s;
	cin>>s;
	if(s.size()==2){
		if(s.at(0)==s.at(1)){
			cout<<"1 2"<<endl;
		}
		else{
			cout<<"-1 -1"<<endl;
		}
		return 0;
	}

	REP(i,0,s.size()-2){
		lli data[26]={0};
		data[s.at(i)-'a']++;
		data[s.at(i+1)-'a']++;
		data[s.at(i+2)-'a']++;
		REP(j,0,26){
			if(data[j]==2){
				cout<<i+1<<" "<<i+3<<endl;
				return 0;
			}
		}
	}
	cout<<"-1 -1"<<endl;

	return 0;
}