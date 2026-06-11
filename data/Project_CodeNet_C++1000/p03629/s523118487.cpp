/* --- author: dxm --- */
#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define fst first
#define snd second
typedef long long ll;
inline void Fail(){printf("0");exit(0);}

const int maxn=200005;
const int maxm=30;
int n;
char c[maxn];
string s,ans;
int nxt[maxn][maxm],dp[maxn];
 
int main(){
	scanf("%s",c);s=c;n=s.size();s="*"+s;
	rep(j,26)nxt[n+1][j]=n+1;
	for(int i=n;i>=1;i--)rep(j,26){
		if(s[i]-'a'==j)nxt[i][j]=i;
		else nxt[i][j]=nxt[i+1][j];
	}
	dp[n+1]=0;
	for(int i=n;i>=0;i--){
		dp[i]=INF;
		rep(j,26)dp[i]=min(dp[i],dp[nxt[i+1][j]]+1);
//		cout<<dp[i]<<endl;
	}
//	printf("%d\n",dp[0]);
	int cur=0,now=0;
	while(cur<n){
		now++;
		rep(i,26){
			if(now+dp[nxt[cur+1][i]]==dp[0]){
				cur=nxt[cur+1][i]; 
				ans+=(char)(i+'a');
				break;
			}
		}
	}
	printf("%s",ans.c_str());
	return 0;
}

/*
Input:
-----------------
Output:
*/