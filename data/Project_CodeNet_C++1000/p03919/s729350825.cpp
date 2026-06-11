#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
const ll mod = 1e9 + 7;
const int INF = 1e9;

int main() {
	cin.sync_with_stdio(false);
	int H, W;
	cin >> H >> W;
	int h, w;
	rep(i, H) {
		rep(j, W) {
			string s;
			cin >> s;
			if (s == "snuke") {
				h = i; w=j;
			}
		}
	}
	cout<<(char)('A' + w)<< h+1 << endl;
	return 0;
}