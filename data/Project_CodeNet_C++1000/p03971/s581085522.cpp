#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,a,b;
	string input;
	cin >> n >> a >> b;	
	cin >> input;
	int passed =0;
	int bPassed =1;
	for(int i = 0;i<n;i++) {
		if(passed < (a+b) && input[i] != 'c') {
			if(input[i] == 'a') {
				cout << "Yes\n";
				passed++;
			}
			else if(input[i] == 'b' && bPassed <= b) {
				cout << "Yes\n";
				passed++;
				bPassed++;
			}
			else 
				cout << "No\n";
		}
		else
			cout << "No\n";
	}
}
