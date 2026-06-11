#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	string s;
	cin >> s;
	int n=s.length();
	bool bl=(s[0]==s[n-1]);

	if((n%2)^bl) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}