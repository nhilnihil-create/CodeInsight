#include <bits/stdc++.h>
using namespace std;

string s;
int n, ans;

int check(int n, string s){
	if(s.compare(0,n/2, s.substr(n/2, n/2))==0){
		return n;
	}

	return check(n-2, s);
}

int main() {
	cin >> s;
	n = s.size();
	ans = check(n, s.substr(0, n-2));
	cout << ans << endl;
}