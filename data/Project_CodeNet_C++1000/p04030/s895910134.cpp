#include <bits/stdc++.h>
using namespace std;

int main(){
#ifdef _DEBUG
	freopen("in" , "r", stdin );
	freopen("out", "w", stdout);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
	string s; char c;
	while(cin >> c){
		if(c == 'B' && s.size()) s.erase(prev(s.end()));
		if(c != 'B') s += c;
	}
	cout << s << '\n';
}
