
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<deque>
#include<list>


using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
const int BIG_INT = 1000000000;

int n, k;
vector<int> a;

bool isNeed(int id) {
	vector<vector<bool>> dp(n+1, vector<bool>(k,false));
	dp[0][0] = true;
	for (int i = 0;i < n;i++) {
		
		for (int j = k-1; j >=0;j--) {
			
			dp[i + 1][j] = dp[i][j];
			
			if (i != id && dp[i][j] == true && a[i] + j <k) {
				dp[i + 1][a[i] + j] = true;
				
			}

			
		}
	}

	for (int i = max(k-a[id],0); i < k;i++) {
		//cout << id <<" " << i << " " << dp[n][i] << endl;
		if (dp[n][i]) {
			
			return true;
			
		}
		
	}
	return false;
}

int main() {
	
	cin >> n >> k;
	a=vector<int>(n);
	for (int i = 0; i < n;i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	if (isNeed(0)) {
		cout << 0 << endl;
	}
	else if (!isNeed(n - 1)) {
		cout << n << endl;
	}
	else {
		int r = 0;
		int l = n - 1;
		int mid = (r + l) / 2;
		while (r != mid) {
			if (isNeed(mid)) {
				l = mid;
			}
			else {
				r = mid;
			}

			mid = (r + l) / 2;
			//cout << mid << endl;
		}



		cout << l << endl;
	}
	
}



