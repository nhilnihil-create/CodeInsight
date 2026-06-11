#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	int n;
	scanf("%d" , &n);
	string s, t;
	cin >> s >> t;
	int sub = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == t[0]) {
			int j = 0;
			while (j < n && i < n && s[i] == t[j]) {
				i++;
				j++;
				sub++;
			}
			if (j < n && i < n){
				sub = 0;
			}
			i--;
		}
	}
	cout << 2 * n - sub << endl;
}
