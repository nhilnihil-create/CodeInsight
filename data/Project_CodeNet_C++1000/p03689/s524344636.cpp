#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
#define int long long
#define ll long long
#define vel vector<int>
#define vvel vector<vel>
#define veb vector<bool>
#define pin pair<int,int>
#define mp make_pair 
#define int long long
using namespace std;
void mmin(int &a, int b) { a = min(a, b); }
signed main() {
	int h, w, h0, w0;
	cin >> h >> w >> h0 >> w0;
	int a = h / h0;
	int r = h % h0;
	if (r > 0) {
		cout << "Yes" << endl;
		int x = a + 1;
		int y = (a+1) * (h0 - 1) + 1;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (i%h0 == h0-1) { cout << -y; }
				else { cout << x; }
				if (j + 1 < w) { cout << " "; }
				else { cout << endl; }
			}
		}
	}
	else {
		int qa = w / w0;
		int qr = w % w0;
		if (qr > 0) {
			cout << "Yes" << endl;
			int x = qa + 1;
			int y = (qa+1) * (w0 - 1) + 1;
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (j%w0 == w0 - 1) { cout << -y; }
					else { cout << x; }
					if (j + 1 < w) { cout << " "; }
					else { cout << endl; }
				}
			}
		}
		else { cout << "No" << endl; }
	}
	return 0;
}