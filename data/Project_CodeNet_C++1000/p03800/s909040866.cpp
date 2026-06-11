#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;
typedef pair<int, int> P;

int N;
string S;
string ans;
bool check() {
	for (int i = 0; i < N; i++) {
		if (S[i] == 'o') {
			if (ans[i + 1] == 'S') {
				if (ans[i] == 'S') {
					ans += 'S';
				}
				else {
					ans += 'W';
				}
			}
			else {
				if (ans[i] == 'S') {
					ans += 'W';
				}
				else {
					ans += 'S';
				}
			}
		}
		else {
			if (ans[i + 1] == 'S') {
				if (ans[i] == 'S') {
					ans += 'W';
				}
				else {
					ans += 'S';
				}
			}
			else {
				if (ans[i] == 'S') {
					ans += 'S';
				}
				else {
					ans += 'W';
				}
			}
		}
	}
	//cout << ans << endl;
	if (ans[0] == ans[N] && ans[1] == ans[N + 1]) return true;
	else return false;
}

int main()
{
	cin >> N >> S;
	string tmp;
	ans.push_back('S');
	ans.push_back('S');
	if (check()) {
		for (int i = 1; i <= N; i++) {
			cout << ans[i];
		}
		cout << endl;
		return 0;
	}
	ans = tmp;
	ans.push_back('W');
	ans.push_back('S');
	if (check()) {
		for (int i = 1; i <= N; i++) {
			cout << ans[i];
		}
		cout << endl;
		return 0;
	}
	ans = tmp;
	ans.push_back('S');
	ans.push_back('W');
	if (check()) {
		for (int i = 1; i <= N; i++) {
			cout << ans[i];
		}
		cout << endl;
		return 0;
	}
	ans = tmp;
	ans.push_back('W');
	ans.push_back('W');
	if (check()) {
		for (int i = 1; i <= N; i++) {
			cout << ans[i];
		}
		cout << endl;
		return 0;
	}
	cout << -1 << endl;
}