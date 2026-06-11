#include<bits/stdc++.h>
using namespace std;

const long long INF = 1000000000;

typedef long long ll;

#define writeln(n) cout<<n<<"\n"
#define rep(i,n) for(int i=0; i<(n); ++i)

typedef pair<int, int> P;
typedef pair<string, int> Psi;

vector<int> X[200010];
bool dfs(int from, int pre, int cnt,int goal){
	if(from == goal && cnt ==2 ){
		return true;
	}
	if(cnt >3)return false;

	for(int i=0; i<X[from].size(); i++ ){
		int next = X[from][i];



		if(next != pre){

			if(dfs(next,from,cnt+1,goal))return true;
		}
	}
	return false;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,m; cin>>n>>m;



	rep(i,m){
		int from,to;cin>>from>>to;

		X[from].push_back(to);
		X[to].push_back(from);
	}

	if(dfs(1,0,0,n)){
		writeln("POSSIBLE");
	}else {
		writeln("IMPOSSIBLE");
	}





}
