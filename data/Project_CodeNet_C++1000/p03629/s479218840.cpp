#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;

int n, suff[200005], nxt[200005][26], ini;
string s;

signed main(){
	ios_base::sync_with_stdio(0);
	cin >> s;
	n = s.length();
	s = '*' + s;
	for(int i = n; i >= 1; i--){
		ini |= (1 << (s[i] - 'a'));
		if(ini == ((1 << 26) - 1)){
			suff[i] = suff[i + 1] + 1;
			ini = 0;
		}
		else suff[i] = suff[i + 1];
		//cout << suff[i] << "\n";
	}
	for(int i = 0; i < 26; i++) nxt[n][i] = n + 1;
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < 26; j++) nxt[i][j] = nxt[i + 1][j];
		nxt[i][s[i + 1] - 'a'] = i + 1;
	}
	string ans = "";
	int pos = 0;
	//cout << suff[1] << "\n";
	//cout << s.length() << "\n";
	for(int i = 1; i <= suff[1] + 1; i++){
		//cout << pos << "\n";
		for(int j = 0; j < 26; j++){
			//if(nxt[pos][j] > n) continue;
			//if(nxt[pos][j] == n && i != (suff[1] + 1)) continue;
			//cout << i << " " << j << " " << nxt[pos][j] + 1 << " " << suff[nxt[pos][j] + 1] << " " << suff[1] + 1 - i << "\n";
			if(nxt[pos][j] <= n && suff[nxt[pos][j] + 1] >= (suff[1] + 1 - i) && (i != (suff[1] + 1))) continue;
			if(i == (suff[1] + 1) && nxt[pos][j] <= n) continue;
			pos = nxt[pos][j];
			ans += char(97 + j);
			break;
		}
	}
	cout << ans;
}
