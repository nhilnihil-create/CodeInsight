#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <functional>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define for1(i, m, n) for(int i = m;i < n;i++)
#define ll long long
#define endl '\n'
using namespace std;


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h, w;
	cin >> h >> w;
	string s[26][26];
	bool flag = false;
	rep(i, h) {
		rep(j, w) {
			cin >> s[i][j];
			if (s[i][j] == "snuke") {
				h = i;
				w = j;
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	cout << char(w + 'A') << h + 1 << endl;
	return 0;
}