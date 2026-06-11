#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int h, w; cin >> h >> w;
	pair<char,int> ans;
	for(int i = 1; i <= h; i++) {
		for(int j = 0; j < w; j++) {
			string s; cin >> s;
			if(s == "snuke") {
				ans = make_pair('A' + j, i);
			}
		}
	}
	cout << ans.first << ans.second << endl;
		
	return 0;                                              
}
	
