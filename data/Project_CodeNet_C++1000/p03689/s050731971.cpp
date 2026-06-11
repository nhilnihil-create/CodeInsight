
#include "bits/stdc++.h"
using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
const int inf = 1000000001;
const ll INF = 2e18 * 2;
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };

int main() {
	int H, W, h, w, i, j;
	cin >> H >> W >> h >> w;
	if (H%h == 0 && W%w == 0) {
		cout << "No" << endl;
		return 0;
	}
	else {
		cout << "Yes" << endl;
	}
	bool yoko;
	if (W%w) {
		yoko = true;
	}
	else {
		yoko = false;
	}

	if (!yoko) {
		swap(H, W);
		swap(h, w);
	}
	//DEBUG(H); DEBUG(W); DEBUG(h); DEBUG(w);
	vi s(W + 1, -1);
	s[0] = 0;
	for (i = 1; i < w; i++) {
		s[i] = 10000 - i;
	}
	for (i = w; i <= W; i++) {
		s[i] = s[i - w] - 1;
	}
	//DEBUG_VEC(s);
	vi a(W);
	for (i = 0; i < W; i++) {
		a[i] = s[i + 1] - s[i];
	}
	if (yoko) {
		for (i = 0; i < H; i++) {
			for (j = 0; j < W; j++) {
				cout << a[j] << " ";
			}
			cout << endl;
		}
	}
	else {
		for (i = 0; i < W; i++) {
			for (j = 0; j < H; j++) {
				cout << a[i] << " ";
			}
			cout << endl;
		}
	}
}