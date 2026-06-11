#include<bits/stdc++.h>
using namespace std;
const bool DBG = 1;

#define TRACE(x)    x
#define WATCH(x)    TRACE(cout << #x" = " << x << endl)
#define WATCHR(a,b) TRACE(for(auto it=a; it!=b;) cout<<*(it++)<<" ";cout<<endl)
#define WATCHC(V)   TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pair<int,int>> vpii;

void fill(vector<vector<char>> &pat, int d, char c, int i, int j) {
	int dimI = pat.size();
	int dimJ = pat[0].size();
	for(int k = 0; k < d/2; k++) {
		for(int l = k; l < d-k; l++) {
			if(j+l < 0 || j+l >= dimJ) continue;
			if(i+k >= 0 && i+k < dimI) pat[i + k][j + l] = c;
			if(i-k >= 0 && i-k < dimI) pat[i - k][j + l] = c;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);

	int H, W, d;
	cin >> H >> W >> d;

	if(d % 2 == 1) {
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				int v = (i % 2) ^ (j % 2);
				if(v) {
					cout << 'R';
				} else {
					cout << 'Y';
				}
			}
			cout << endl;
		}
	} else {
		vector<vector<char> > pat(2*d, vector<char>(2*d));
		fill(pat, d, 'R', 0, 0);
		fill(pat, d, 'R', d, d);
		fill(pat, d, 'R', 2*d, 0);
		fill(pat, d, 'Y', d, 0);
		fill(pat, d, 'Y', 0, d);
		fill(pat, d, 'Y', 2*d, d);
		fill(pat, d, 'G', d/2, d/2);
		fill(pat, d, 'G', 3*d/2, -d/2);
		fill(pat, d, 'G', 3*d/2, 3*d/2);
		fill(pat, d, 'B', d/2, -d/2);
		fill(pat, d, 'B', d/2, 3*d/2);
		fill(pat, d, 'B', 3*d/2, d/2);

		int D = 2*d;
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				cout << pat[i%D][j%D];
			}	cout << endl;
		}
	}

	return 0;
}
