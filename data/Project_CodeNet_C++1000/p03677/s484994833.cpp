#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int>> PQ;

const int INF = 2e9;
const int MOD = 1e9+7;
const int MAX = 1e5+10;
const lint LNF = 2e18;

int n, m, A[MAX];
lint now, ans=LNF;
lint P[MAX], Q[MAX];

int dist(int a, int b){
	return (b>=a) ? b-a : b+m-a;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>A[i];

	for(int i=2; i<=n; i++){
		now += min(dist(A[i-1], A[i]), 1+dist(1, A[i]));
	}

	for(int i=2; i<=n; i++){
		int l = A[i-1]%m+1, r = A[i];
		P[l]--, P[r]++;
		if(l>r) P[m]++, P[1]--;
		Q[r] += dist(A[i-1], A[i])-1;
	}

	lint sum1=0, sum2=0;
	for(int i=1; i<=m; i++){
		now += sum1 + sum2; sum2=0;
		ans = min(ans, now);
		sum1+=P[i], sum2+=Q[i];
	}

	cout<<ans<<'\n';

	return 0;
}
