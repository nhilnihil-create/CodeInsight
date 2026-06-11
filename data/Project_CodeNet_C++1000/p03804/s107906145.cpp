#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	string a[n], b[m];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<m; i++) {
		cin >> b[i];
	}
	for (int i=0; i+m-1<n; i++) {
		for (int j=0; j+m-1<n; j++) {
			bool same = true;
			for (int r=0; r<m && same; r++) {
				for (int c=0; c<m && same; c++) {
					if (a[i+r][j+c] != b[r][c]) same = false;
				}
			}
			if (same) {cout << "Yes"; return 0;}
		}
	}
	cout << "No";
}