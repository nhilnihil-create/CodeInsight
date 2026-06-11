#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>

using namespace std;
typedef long long int ll;
typedef pair<int, ll> P;
const ll MOD=1e9+7;

int main()
{
	ll n;
	cin>>n;
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	if(n==2){
		cout<<4<<endl;
		return 0;
	}
	ll dp[2000001], sum[2000001];
	dp[n]=n;
	dp[n-1]=n*n%MOD;
	for(int i=n+1; i<=2*n; i++) dp[i]=1;
	sum[2*n]=1;
	for(int i=2*n-1; i>=n-1; i--) sum[i]=(sum[i+1]+dp[i])%MOD;
	for(int i=n-2; i>=1; i--){
		dp[i]=(dp[i+1]+(n-1)*(n-1)+sum[i+3]+MOD-sum[n+i+2])%MOD;
		sum[i]=(sum[i+1]+dp[i])%MOD;
	}
	cout<<dp[1]<<endl;
    return 0;
}