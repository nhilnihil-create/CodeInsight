#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long


int main()
{
	int N;
	string S;
	cin >> N >> S;
	string ans = "";
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '(') {
			ans += '(';
			cnt++;
		}
		else {
			if (cnt != 0) {
				ans += ')';
				cnt--;
			}
			else {
				ans = '(' + ans + ')';

			}
		}
	}
	for (int i = 0; i < cnt; i++) {
		ans += ')';
	}
	cout << ans << endl;
}
