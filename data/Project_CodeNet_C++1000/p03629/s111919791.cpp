#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int p[300000][26];
int dp[300000];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	// p[i][j]:i番目以降で文字jが出てくる最も早い番目
	// dp[i]:i文字目以降で何回アルファベットをコンプしているか

	string s;cin>>s;
	rep(i,26) p[s.size()][i]=s.size()+1;
	memset(dp,0x3f,sizeof(dp));
	dp[s.size()+1]=0;
	dp[s.size()]=1;
	for(int i=s.size()-1;i>=0;i--){
		rep(j,26){
			if(s[i]-'a'==j){
				p[i][j]=i+1;
			}
			else p[i][j]=p[i+1][j];
			if(dp[p[i][j]]+1 < dp[i]){
				dp[i]=min(dp[i],dp[p[i][j]]+1);
			}
		}
	}

	//　コンプ回数が小さくなる最も早い文字で文字列を作っていく

	int pos=0;
	string ans;
	while(pos!=s.size()+1){
		rep(i,26){
			if(dp[p[pos][i]]==dp[pos]-1){
				ans+='a'+i;
				pos=p[pos][i];
				break;
			}
		}
	}
	cout<<ans<<endl;
}