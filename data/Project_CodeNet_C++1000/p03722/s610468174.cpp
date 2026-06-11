#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <string.h>
#include <algorithm>
#define mod 1000000007
#define inf 1LL<<61
#define ll long long
#define pr pair<int,int>
#define all vec.begin(),vec.end()
#define REP(i,a,b) for (int i = a; i < b; i++)
#define fi first
#define se second
#define pushb push_back
#define makep make_pair

using namespace std;

int main(){
	int nmax = 1001;
	int mmax = 2001;
	int a[mmax];
	int b[mmax];
	ll c[mmax];
	int N, M;
	cin >> N >> M;

	REP(i,0,M){
		cin >> a[i] >> b[i] >> c[i];
	}

	ll dp[nmax];
	REP(i,0,N)
		dp[i] = -(inf);
	dp[0] = 0;
	REP(i,0,N-1){
		REP(i,0,M){
			if(dp[a[i] - 1] == -(inf))
				continue;
			dp[b[i]-1]=max(dp[b[i]-1], dp[a[i] -1] + c[i]);
		}
	}
	ll ans = dp[N-1];
	REP(i,0,N-1){
		REP(i,0,M){
			if(dp[a[i] - 1] == inf)
				continue;
			dp[b[i]-1]=max(dp[b[i]-1], dp[a[i] -1 ] + c[i]);
		}
	}
	if(ans != dp[N-1])
		cout << "inf";
	else
		cout << ans;
	
	return 0;
}

