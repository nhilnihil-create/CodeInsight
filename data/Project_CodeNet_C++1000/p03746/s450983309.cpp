#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007

signed main(){

	lli n,m;
	cin>>n>>m;

	vector<vector<lli>> v(n);

	REP(i,0,m){
		lli a,b;
		cin>>a>>b;
		a--,b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	deque<lli> d;
	bool visited[100000]={};
	for(lli i=0;i<n;i++){
		if(!v[i].empty()){
			d.push_back(i);
			visited[i]=true;
			break;
		}
	}
	while(true){
		bool update=false;
		lli a = d.back();
		for(lli i=0;i<v[a].size();i++){
			lli b=v[a][i];
			if(!visited[b]){
				d.push_back(b);
				visited[b]=true;
				update=true;
				break;
			}
		}
		if(!update)break;
	}
	while(true){
		bool update=false;
		lli a = d.front();
		for(lli i=0;i<v[a].size();i++){
			lli b=v[a][i];
			if(!visited[b]){
				d.push_front(b);
				visited[b]=true;
				update=true;
				break;
			}
		}
		if(!update)break;
	}
	cout<<d.size()<<endl;
	for(auto e:d){
		cout<<e+1<<" ";
	}
	cout<<endl;

	return 0;
}