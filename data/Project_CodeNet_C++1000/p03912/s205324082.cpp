#include<bits/stdc++.h>

#define FOR(i, a, b) for(int(i)=(a);(i)<(b);(i)++)
#define REP(i, n) FOR((i), 0, (n))

#define RFOR(i, b, a) for(int(i)=(b); (i)>=(a); (i)--)
#define RREP(i, n) FOR((i), (n), 0)

#define pb push_back
#define mp make_pair 

using namespace std;

const int INF=INT_MAX/4;
const int MOD=1000000007;
const double EPS=1e-14;

const bool debug_flag=true;

void debug(string str){
	if(debug_flag){
		cout<<str<<endl;
	}
}

void debugs(string str){
	if(debug_flag){
		cout<<str;
	}
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout.precision(10);

	int N, M, x;
	cin>>N>>M;
	vector<vector<int> > g;
	g.resize(M);
	REP(i, N){
		cin>>x;
		g[x%M].pb(x);
	}

	int ans=0, s, t, S, T, cnt;
	FOR(i, 1, M/2.0){
		if(g[i].size()<g[M-i].size()){
			s=i;
			t=M-i;
			S=g[s].size();
			T=g[t].size();
		}else{
			s=M-i;
			t=i;
			S=g[s].size();
			T=g[t].size();
		}
		sort(g[t].begin(), g[t].end());
		cnt=0;
		REP(j, g[t].size()){
			if(g[t][j]==g[t][j+1] && cnt*2<=T-S-2){
				cnt++;
				j++;
			}
		}
		ans+=cnt+S;
	}

	ans+=g[0].size()/2;
	if(M%2==0){
		ans+=g[M/2].size()/2;
	}

	cout<<ans<<endl;

	return 0;
}

