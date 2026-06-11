#include<bits/stdc++.h>
#define fo(i,a,b) for((i)=(a);i<=(b);i++)
#define rfo(i,a,b) for((i)=(a);i>=(b);i--)
#define inrange(x,y,z) (((x)>=(y))&&((x)<=(z)))
#define ALL(vec) ((vec).begin(),(vec).end())
#define SOR(vec) sort(ALL(vec))
#define UNI(vec) (vec).erase(unique(ALL(vec)),(vec).end())
using namespace std;
string s;
int n,nxt[200100][26],dp[200100];
int main(){
	#ifdef FILIN
		#ifndef DavidDesktop
			freopen(FILIN,"r",stdin);
			freopen(FILOUT,"w",stdout);
		#endif
	#endif
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s;
	n=s.size();
	for(int i=0;i<26;i++) nxt[n][i]=n;
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<26;j++)
			nxt[i][j]=nxt[i+1][j];
		nxt[i][s[i]-'a']=i;
		dp[i]=1e9;
	}
	dp[n]=1;
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<26;j++){
			dp[i]=min(dp[i],dp[nxt[i][j]+1]+1);
		}
	}
	int idx=0;
	for(int i=dp[0];i>=0;i--){
		for(int j=0;j<26;j++){
			if(dp[idx]==dp[nxt[idx][j]+1]+1){
				cout<<(char)(j+'a');
				idx=nxt[idx][j]+1;
				break;
			}
		}
	}
	cout<<endl;
	return 0;
}
