/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
//
//		  _____       _           _        _
//		 / ____|     | |         (_)      | |
//		| (___   __ _| |__  _   _ _       | | __ _ _ __   __ _
//		 \___ \ / _` | '_ \| | | | |  _   | |/ _` | '_ \ / _` |
//		 ____) | (_| | |_) | |_| | | | |__| | (_| | | | | (_| |
//		|_____/ \__,_|_.__/ \__,_| |  \____/ \__,_|_| |_|\__,_|
//		                        _/ |
//		                       |__/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
//cout<<fixed<<showpoint<<setprecision(12)<<ans<<endl;
#define int long long int
#define double long double
#define PI acos(-1)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define endl "\n"

void print1d(const vector<int>& vec) {for (auto val : vec) {cout << val << " ";} cout << endl;}

void print2d(const vector<vector<int>>& vec) {for (auto row : vec) {for (auto val : row) {cout << val << " ";} cout << endl;}}

void solve(vector<int>& arr, int r, int c) {

	int idx = 1;
	int dp[r][c];

	for (int i = 0; i < r; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < c; j++) {
				if (arr[idx - 1] == 0)
					idx++;
				dp[i][j] = idx;
				arr[idx - 1]--;

			}
		} else {
			for (int j = c - 1; j >= 0; j--) {
				if (arr[idx - 1] == 0)
					idx++;
				dp[i][j] = idx;
				arr[idx - 1]--;
			}
		}
	}


	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

}

signed main() {
	crap;

	int r, c;
	cin >> r >> c;

	int n;
	cin >> n;

	vi arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	solve(arr, r, c);

	return 0;
}