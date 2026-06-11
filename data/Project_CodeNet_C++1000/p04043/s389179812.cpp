#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v(3);
  	for(auto &el : v) cin >> el;
  	sort(begin(v), end(v));
  	if(v[0] == 5 && v[1] == 5 && v[2] == 7) cout << "YES" << endl;
  	else cout << "NO" << endl;
	return 0;
}