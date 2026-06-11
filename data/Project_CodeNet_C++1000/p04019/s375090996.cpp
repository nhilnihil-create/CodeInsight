#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
	string s;
	cin >> s;
	int n = 0, ss = 0, w = 0, e = 0;
	rep(i, s.size()){
		if(s[i] == 'N') n++;
		if(s[i] == 'S') ss++;
		if(s[i] == 'W') w++;
		if(s[i] == 'E') e++;
	}
	if(n && ss && w && e) cout << "Yes" << endl;
	else if(n && ss && !w && !e) cout << "Yes" << endl;
	else if(!n && !ss && w && e) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}