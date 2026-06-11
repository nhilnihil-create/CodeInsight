#include<iostream>
#include<cstdio>
#include<math.h>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define INF 999999
#define EPS 1.0e-6

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int, P> PP;

ll k;
ll d[55];

int main()
{
	cin >> k;
	for (int i = 0; i < 50; i++) {
		d[i] = 49;
	}
	ll j = k / 50;
	int l = k % 50;
	for (int i = 0; i < 50; i++) {
		d[i] += j;
	}
	if (l != 0) {
		for (int i = 1; i <= 50; i++) {
			if (i > l)d[i - 1] -= l;
			else d[i - 1] += 51 - l;
		}
	}
	cout << 50 << endl;
	for (int i = 0; i < 49; i++) {
		cout << d[i] << " ";
	}
	cout << d[49] << endl;
	
	return 0;
}