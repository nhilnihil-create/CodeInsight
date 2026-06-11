#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s; cin >> s;
	if(s.size() >= 4 && s.substr(0, 4) == "YAKI") cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;                                              
}
	
