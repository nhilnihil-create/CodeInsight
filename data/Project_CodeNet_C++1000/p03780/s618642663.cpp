#include <bits/stdc++.h>

using namespace std;

typedef long long       ll;

#define all(x)            (x).begin(),(x).end()
#define Sort(x)            sort(all(x))
#define A               first
#define B               second
#define sep             ' '
#define fast_io         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random     mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count())

const int MAX1 = 5e3+10,
         Md = 1e9+7,
		 Base = 257;

ll n, m, sum, ans, adad, num[MAX1], dp[MAX1];

bool Check(ll flg){
	fill(dp, dp+MAX1, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i){
		if (i == flg)	continue;
		for (int j = m-1; j >= num[i]; --j){
			dp[j] |= dp[j-num[i]];
		}
	}
	for (int i = m-1; i >= m-num[flg]; --i){
		if (dp[i])	return false;
	}
	return true;
}

int main(){
    fast_io;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
    	cin >> num[i];
	}
	sort(num+1, num+n+1);
	ll L = 0, R = n+1, Mid;
	while (R-L > 1){
		Mid = (R+L)/2;
		if (Check(Mid))	L = Mid;
		else	R = Mid;
	}
	cout << L << '\n';
    return 0;
}
/*               now or never                 */
