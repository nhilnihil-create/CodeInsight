#include <bits/stdc++.h>
using namespace std;

int main(){
#ifdef _DEBUG
	freopen("in" , "r", stdin );
	freopen("out", "w", stdout);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
	set<int> s;
	for(int i = 0; i < 3; i++){
		int t; cin >> t;
		s.insert(t);
	}
	cout << s.size() << '\n';
}
