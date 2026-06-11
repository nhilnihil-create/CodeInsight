#include<bits/stdc++.h>
#define int long long
using namespace std;
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    string s;
    cin >> s;
    if(s.length() > 2) {
		int l = -1 , r = -1;
		for(int i = 0; i < s.length()-2; i++) {
			map<char , int> map;
			for(int j = 0; j < 3; j++) map[s[i+j]]++;
			int found = -1;
			for(auto p:map) {
				if(p.second >= 2) {l = i+1 , r = i+3 , found = 1;}
			}
			if(found == 1) break;
		}
		cout << l << " " << r << "\n";
	}
	else if(s[0] == s[1]) cout << "1 2" << "\n";
	else cout << "-1 -1" << "\n";
 
    return 0;
}
