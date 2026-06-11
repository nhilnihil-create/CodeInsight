#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
//setprecision(15)

int main() {
	int N, A, B; cin >> N >> A >> B;
	string s; cin >> s;
	int a = 0, b = 0;
	rep(i, N) {
		if (s[i] == 'a') {
			if (a + b < A + B) {
				cout << "Yes" << endl;
				a++;
			} else {
				cout << "No" << endl;
			}
		} else if (s[i] == 'b') {
			if ((a + b < A + B) && b < B) {
				cout << "Yes" << endl;
				b++;
			} else {
				cout << "No" << endl;
			}
		} else {
			cout << "No" << endl;
		}
	}
}