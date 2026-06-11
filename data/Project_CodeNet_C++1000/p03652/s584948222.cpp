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

lli data[400];
lli n,m;

void solve(map<lli,vector<lli>> &v,set<lli> &s){
	REP(i,0,400)data[i] = 0;

	for(lli i=0;i<n;i++){
		for(lli j=0;j<m;j++){
			auto itr = s.find(v[i][j]);
			if(itr == s.end())continue;

			data[v[i][j]]++;
			break;
		}
	}
}

signed main(){

	cin>>n>>m;

	map<lli,vector<lli>> v;

	REP(i,0,n)REP(j,0,m){
		lli tmp;
		cin>>tmp;
		tmp--;
		v[i].push_back(tmp);
	}

	set<lli> sports;

	REP(i,0,m)sports.insert(i);

	lli ans = INF;

	while(sports.size()){
		solve(v,sports);

		lli maxSports=0;
		lli maxIndex =0;
		for(lli i=0;i<m;i++){
			if(maxSports < data[i]){
				maxSports = data[i];
				maxIndex = i;
			}
		}
		if(DEBUG)cout<<"maxSports="<<maxSports<<endl;
		if(DEBUG)cout<<"maxINdex="<<maxIndex<<endl;
		ans = min(ans,maxSports);
		sports.erase(maxIndex);
	}

	cout<<ans<<endl;




	return 0;
}