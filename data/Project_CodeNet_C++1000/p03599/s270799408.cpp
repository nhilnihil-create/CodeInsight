#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;


int main(){
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	int dp[3001]; //合計i[g]の水があるときの最大の砂糖の量

	for (int i = 0; i <= 3000; i++){
		dp[i] = -1;
	}

	dp[0] = 0;

	for (int i = 0; i <= f; i++){
		if (dp[i] != -1){
			if (i+100*a <= f) dp[i+100*a] = max(dp[i+100*a], dp[i]);
			if (i+100*b <= f) dp[i+100*b] = max(dp[i+100*b], dp[i]);
			int max_suger = i/100*e;
			for (int j = 0; j*c <= max_suger; j++){
				for (int k = 0; j*c + k*d <= max_suger; k++){
					if (i + j*c + k*d <= f){
						dp[i] = max(dp[i], j*c + k*d);
					}
				}
			}
		}
	}
	double ans = -1;
	int ansi = -1;

	for (int i = 0; i <= f; i++){
		if (dp[i] != -1){
			if (i + dp[i] <= f){
				if (ans < (double)dp[i]/(double)(i+dp[i])){
					ans = (double)dp[i]/(double)(i+dp[i]);
					ansi = i;
				}
			}
		}
	}
	if (ansi == -1) cout << 0 << endl;
	else cout << ansi+dp[ansi] << " " << dp[ansi] << endl;
	return 0;
}