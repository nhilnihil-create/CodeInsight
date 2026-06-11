#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

string s;
int cnt[26][100001];

int main(){
	//IO("input.txt", "output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	for(int i = 0; i < 26; i++){
		pair<int, int> mn = {INT_MAX, -1};
		for(int j = 1; j <= (int)s.length(); j++){
			if(s[j - 1] == 'a' + i) cnt[i][j] = cnt[i][j - 1] + 1;
			else cnt[i][j] = cnt[i][j - 1] - 1;
			if(cnt[i][j] - mn.first > 0){
				cout << mn.second << " " << j << "\n";
				return 0;
			}
			mn = min(mn, {cnt[i][j - 1], j});
		}
	}
	cout << "-1 -1\n";
	return 0;
}