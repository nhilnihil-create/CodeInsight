#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<map>
#define ran(x) (x).begin(),(x).end()
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n), t(m);
	for(int i = 0; i < n; ++i)
		cin >> s[i];
	for(int j = 0; j < m; ++j)
		cin >> t[j];
	int ans = 0;
	int k = 0;
	for(int f = 0; f < n - m + 1; ++f) {
		int l = 0;
		for(int h = 0; h < n - m + 1; ++h) {
			int cou = 0;
			for(int i = 0; i < m; ++i) {
				for(int j = 0; j < m; ++j) {
					if(t[i][j] == s[i + k][j + l])
						++cou;
				}
			}
			if(cou == m * m)
				ans = 1;
			++l;
		}
		++k;
	}
	cout << (ans == 1 ? "Yes" : "No") << endl;
}