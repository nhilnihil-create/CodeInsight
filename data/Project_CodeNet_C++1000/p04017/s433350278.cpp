#include<bits/stdc++.h>
#define MAXN 100005
#define INF int(1e9)
#define dis(l,r) (x[r] - x[l])
#define LL long long
using namespace std;

int N,L,Q;
LL x[MAXN];

int dp[MAXN][21];

void init(){
	
	int p = 1;
	for(int i=1;i<=N;i++){
		while(p+1<=N && dis(i,p+1)<=L) ++p;
		
		dp[i][0] = p;
	}
	
	for(int j=1;j<=20;j++){
		for(int i=1;i<=N;i++){
			dp[i][j] = dp[dp[i][j-1]][j-1];
		}
	}
}

int walk(int s, int t){
	int ans = 0;
	for(int j=20;j>=0;j--){
		if(dp[s][j] && dp[s][j] < t){
			ans += (1<<j);
			s = dp[s][j];
		}
	}
	return ans + 1;
}

int main(){
	
	cin>>N;
	
	for(int i=1;i<=N;i++){
		cin>>x[i];
	}	
	
	cin>>L>>Q;
	
	init();
	
	int s,t;
	while(Q--){
		cin>>s>>t;
		if(s > t) swap(s,t);
		cout<<walk(s,t)<<endl;
	}
	return 0;
}

