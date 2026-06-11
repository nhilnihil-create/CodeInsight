#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//----
const int N=5010;
const int MOD=1e9+7;
int n;
char s[N];
int dp[N][N];
int main(){
	scanf("%d%s", &n, s);
	dp[0][0]=1;
	int m=strlen(s);
	rep(i, 1, n+1){
		dp[i][0]=(dp[i-1][0]+dp[i-1][1]*2%MOD)%MOD;
		rep(j, 1, i+1)dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1]*2%MOD)%MOD;
	}
	printf("%d\n", dp[n][m]);
	return 0;
}
/*
3
0
5

300
1100100
519054663

5000
01000001011101000100001101101111011001000110010101110010000
500886057
*/