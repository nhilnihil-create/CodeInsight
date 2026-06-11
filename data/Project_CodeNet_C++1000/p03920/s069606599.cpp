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

#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 1000000000

using namespace std;

int main(void) {
	int n;
	int p;
	cin >> n;

	FOR(i, 1, 10e7) {
		if (n <= (i*i + i) / 2) {
			p = i;
			break;
		}
	}
	RFOR(i, p, 1) {
		if (n - i >= 0) {
			cout << i << endl;
			n -= i;
		}
		if (n == 0) {
			break;
		}
	}

	return 0;
}