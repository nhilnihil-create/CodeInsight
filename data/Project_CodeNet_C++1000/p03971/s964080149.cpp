#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	int passed = 0;
	int overseas = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'a') {
			if(passed < a + b) {
				cout << "Yes\n";
				passed += 1;
			}
			else {
				cout << "No\n";
			}
		}
		else if(s[i] == 'b') {
			overseas += 1;
			if(passed < a + b) {
				if(overseas <= b) {
					passed += 1;
					cout << "Yes\n";
				}
				else {
					cout << "No\n";
				}
			}
			else {
				cout << "No\n";
			}
		}
		else if(s[i] == 'c') {
			cout << "No\n";
		}
	}
	return 0;
}