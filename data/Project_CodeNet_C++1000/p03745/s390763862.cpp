#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int judge(int a, int b) {
	int res = 0;
	if (a < b)res = 1;
	else if (a > b)res = -1;
	return res;
}

int main() {
	int n, a,ba,cnt=1,flag;
	cin >> n;
	if (n == 1 || n == 2) { cout << cnt << endl; return 0; }
	cin >> ba >> a;
	flag = judge(ba, a);
	ba = a;
	rep(i, n-2) {
		cin >> a;
		if ((ba < a && flag == -1) || (ba > a && flag == 1)) {
				cnt++;flag = 0;
		}
		else {
			if (ba > a)flag = -1;
			if (ba < a)flag = 1;
		}
		ba = a;
	}

	cout << cnt << endl;
	return 0;
}
