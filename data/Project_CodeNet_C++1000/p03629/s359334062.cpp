#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solve(const string& s){
	const int n = s.size();
	vector<int> step(n+2, 0);
	step[n] = 1;
	vector<vector<int>> next(n, vector<int>(26, n+1));
	for(int i=0;i<n;i++){
		for(int j=i;j>=0;j--){
			if(next[j][s[i]-'a'] < n+1) break;
			next[j][s[i]-'a'] = i+1;
		}
	}
	for(int i=n-1;i>=0;i--){
		step[i] = 100000000;
		for(int j=0;j<26;j++){
			step[i] = min(step[i], step[next[i][j]] + 1);
		}
	}
	string res;
	int pos = 0;
	while(pos < n){
		for(int i=0;i<26;i++){
			if(step[pos] == step[next[pos][i]] + 1){
				res += i+'a';
				pos = next[pos][i];
				break;
			}
		}
	}
	return res;
}

int main(){
	string s;
	while(cin >> s){
		cout << solve(s) << endl;
	}
}
