#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;

int main(){
	string s, t;
	cin >> s;
	for(int i=0; i<s.size(); i+=2) t+=s[i];
	cout << t << endl;

	return 0;
}