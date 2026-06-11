#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<list>
#include<bitset>
#include<functional>

#define FOR(i, a, b) for(long long int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for(long long int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 1000000000
#define PI 3.14159265358979

using namespace std;
typedef pair<long long int, long long int> P;




int main(void) {
	long long int h, w, n;
	long long int a, b;
	long long int count[10] = {};
	long long int point = 0;
	long long int mas = 1;
	long long int p;

	cin >> h >> w >> n;

	vector<P>dp(9*100001);

	FOR(i, 1, n) {
		cin >> a >> b;
		FOR(t, 0, 2) {
			FOR(s, 0, 2) {
				if (a - s >= 1 && b - t >= 1&&a-s<=h-2&&b-t<=w-2) {
					dp[point].first = a - s;
					dp[point].second = b - t;
					point++;
				}
			}
		}
	}
	count[0] = (h - 2)*(w - 2);
	sort(dp.begin(), dp.end());

	
	FOR(i, 0, dp.size() - 1) {
		if (dp[i].first != 0) {
			p = i;
			break;
		}
	}
	

	FOR(i,p+1,dp.size()-1) {
		if (dp[i].first == dp[i - 1].first&&dp[i].second == dp[i - 1].second) {
			mas++;
			if (i == dp.size() - 1) {
				count[mas]++;
				count[0]--;
			}
		}
		else {
			count[mas]++;
			if (i == dp.size() - 1) {
				count[1]++;
				count[0]--;
			}
			count[0]--;
			mas = 1;
		}
	}

	FOR(i, 0, 9) {
		cout << count[i] << endl;
	}

	return 0;
}