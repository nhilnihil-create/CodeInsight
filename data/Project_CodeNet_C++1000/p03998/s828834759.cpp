#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb emplace_back
typedef pair<int,int> pi;

int idx[3];
string a,b,c;

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cin >> a >> b >> c;
	char cur = 'a';
	while (1) {
		if (cur == 'a') {
			if (a.size() == idx[0]) {
				cout << 'A';
				break;
			}
			cur = a[idx[0]];
			++idx[0];
		} else if (cur == 'b') {
			if (b.size() == idx[1]) {
				cout << 'B';
				break;
			}
			cur = b[idx[1]];
			++idx[1];
		} else if (cur == 'c') {
			if (c.size() == idx[2]) {
				cout << 'C';
				break;
			}
			cur = c[idx[2]];
			++idx[2];
		}
	}
	return 0;
}
