#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	vector<string> divi = {"dream", "dreamer", "erase", "eraser"};
	string s;
	cin >> s;

	reverse(s.begin(), s.end());
	rep(i, 4) reverse(divi.at(i).begin(), divi.at(i).end());

	bool can = true;
	for(int i = 0; i < s.size();){
		bool can2 = false;
		for(int j = 0; j < 4; j++){
			if(divi.at(j) == s.substr(i, divi.at(j).size())){
				can2 = true;
				i += divi.at(j).size();
			}
		}

		if(!can2){
			can = false;
			break;
		}
	}
	if(can) cout << "YES" << endl;
	else cout << "NO" << endl;
}