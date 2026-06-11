#include <iostream>
#include <string>

using namespace std;

string s;
int nx[200005][26];
int dp[200005], c[200005];

int main(void)
{
	cin >> s;
	s = "#" + s;
	
	for(int i = 0; i < 26; i++) nx[(int)s.size()-1][i] = s.size();
	for(int i = (int)s.size()-2; i >= 0; i--){
		for(int j = 0; j < 26; j++) nx[i][j] = nx[i+1][j];
		nx[i][s[i+1]-'a'] = i+1;
	}
	for(int i = (int)s.size()-1; i >= 0; i--){
		dp[i] = 1e9;
		for(int j = 0; j < 26; j++){
			if(dp[i] > dp[nx[i][j]]+1){
				dp[i] = dp[nx[i][j]]+1;
				c[i] = j;
			}
		}
	}
	
	int p = 0;
	while(p != s.size()){
		cout << (char)(c[p]+'a');
		p = nx[p][c[p]];
	}
	cout << endl;
	
	return 0;
}