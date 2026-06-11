//arc083_d.cpp
//Thu Jan 23 22:53:42 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;

	ll a[n][n],dp[n][n];

	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cin >> a[i][j];
			dp[i][j] = a[i][j];
		}
	}

	for (int k=0;k<n;k++){
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				if (i==k || j==k || i==j || dp[i][k]==LLINF || dp[k][j]==LLINF){
					continue;
				}
				if (a[i][j]==dp[i][k]+dp[k][j]){
					dp[i][j] = LLINF;
				}else if (a[i][j]>dp[i][k]+dp[k][j]){
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}

	ll ans = 0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (dp[i][j]!=LLINF){
				ans += dp[i][j];
			}
		}
	}
	cout << ans/2 << endl;
//	printf("%.4f\n",ans);
}