#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
	string s;
	cin >> s;
	rep(i, 4) cout << s.at(i);
	cout << ' ';
	for(int i=4; i<12; i++) cout << s.at(i);
	cout << endl;
	return 0;
}