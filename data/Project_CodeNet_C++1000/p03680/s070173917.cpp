#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
//setprecision(15)
int A[100000+1];
int main() {
	int N; cin >> N;
	int a[100000];
	rep(i, N) cin >> a[i];
	int tmp = a[0];
	int cnt = 1;
	while (1) {
		if (tmp == 2) {
			cout << cnt << endl; return 0;
		}
		if (A[tmp] == 1) {
			cout << "-1" << endl; return 0;
		}
		A[tmp] = 1;
		tmp = a[tmp-1];
		cnt++;
	}
	cout << "-1" << endl;
}