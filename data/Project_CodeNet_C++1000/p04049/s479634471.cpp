#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

int solve(int p, int q, int k, vector<vector<int>> &V){
	int ret = (k<0?1:0);
	for(auto u : V[q]) if(p != u){
		ret += solve(q,u,k-1,V);
	}
	return ret;
}

int main(){
	int N,K; cin >> N >> K;
	vector<vector<int>> V(N);
	repp(i,1,N){
		int A,B; cin >> A >> B;
		--A; --B;
		V[A].push_back(B);
		V[B].push_back(A);
	}
	int ans = N;
	if(K%2==1){
		repp(i,0,N) for(auto u : V[i]) if(i < u) ans = min(ans,solve(u,i,K/2,V)+solve(i,u,K/2,V));
	} else {
		repp(i,0,N) ans = min(ans,solve(-1,i,K/2,V));
	}
	cout << ans << endl;
	return 0;
}
