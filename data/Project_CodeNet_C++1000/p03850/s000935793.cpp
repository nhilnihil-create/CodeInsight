#include<bits/stdc++.h>
#define MAXN 200005
#define LL long long
#define sum(l,r) (l<=r?(s[r] - s[l-1]):0)
using namespace std;
 
int N;
LL a[MAXN], s[MAXN];
int nxt[MAXN];

LL dp[MAXN][3];
 
int main(){
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	
	cin>>N;
	cin>>a[1];
	
	int N1 = 1;
	char op;
	int x, f = 1; 
	for(int i=1;i<N;i++){
		cin>>op;
		cin>>x;
		if(op=='-') a[++N1] = -x, f = 0;
		else{
			if(f) a[N1] += x;
			else a[++N1] = x, f = 1; 
		}
	}

	N = N1;
	if(N==1){
		cout<<a[1]<<endl;
		return 0;
	}
	
	for(int i=1;i<=N;i++){
		//cout<<a[i]<<" ";
		s[i] = s[i-1] + abs(a[i]);
	}
	//cout<<endl;
	
	memset(dp, 0xf3, sizeof(dp));
	dp[1][0] = a[1];
	
	for(int i=2;i<=N;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				if(a[i]>=0 && k>=j){
					if(k==1) dp[i][j] = max(dp[i][j], dp[i-1][k] - a[i]);
					else dp[i][j] = max(dp[i][j], dp[i-1][k] + a[i]);
				}
				
				if(a[i]<0){
					if(k>=j){
						if(k==1) dp[i][j] = max(dp[i][j], dp[i-1][k] - a[i]);
						else dp[i][j] = max(dp[i][j], dp[i-1][k] + a[i]);
					}
					else if(k==j-1){
						if(j==2) dp[i][j] = max(dp[i][j], dp[i-1][k] - a[i]);
						else dp[i][j] = max(dp[i][j], dp[i-1][k] + a[i]);
					}
				}
			}
		}
	}
	
	//for(int i=2;i<=N;i++) cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
	
	cout<<dp[N][0];
	
	return 0;
}