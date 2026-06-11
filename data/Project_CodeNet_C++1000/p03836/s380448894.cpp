#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
#include<iterator>
#include<list>

using namespace std;

typedef  long long int lint;

#define rep(i, n) for (lint i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define mp make_pair
#define enld endl

int main() {
	lint sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	rep(i, ty - sy) {
		cout << 'U';
	}
	rep(i, tx - sx) {
		cout << 'R';
	}
	rep(i, ty - sy) {
		cout << 'D';
	}
	rep(i, tx - sx) {
		cout << 'L';
	}
	cout << 'L';
	lint dx = tx - sx;
	lint dy = ty - sy;
	rep(i, dy + 1) {
		cout << 'U';
	}
	rep(i, dx + 1) {
		cout << 'R';
	}
	cout << 'D';
	cout << 'R';
	rep(i, dy + 1) {
		cout << 'D';
	}
	rep(i, dx + 1) {
		cout << 'L';
	}
	cout << 'U';
	cout << endl;
}