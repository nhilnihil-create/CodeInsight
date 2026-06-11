#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,x,n) for(int i=x;i<n;i++)
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;
typedef pair<int, int> PI;
typedef vector<int> VI;
LL a[50];
int main() {
	LL K;
	cin >> K;
	LL q = K / 50, r = K % 50;
	rep(i, 50) a[i] = i + q;
	rep(i, r) {
		a[i] += 50;
		rep(j, 50) {
			if (i != j) a[j]--;
		}
	}
	cout << 50 << endl;
	rep(i, 50) {
		cout << a[i] << " ";
	}
}