#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

signed main(){
	int H, W; 
	scanf("%d %d", &H, &W);
	vector<vector<char> > field(H, vector<char> (W));
	vector<int> data(26, 0);
	for(int i = 0; i < H; i++){
		string s; cin >> s;
		for(int j = 0; j < W; j++) {
			field[i][j] = s[j];
			data[field[i][j] - 'a']++;
		}
	}
	bool ok = true;
	int x = H % 2, y = W % 2;
	if(!x && !y){
		for(int i = 0; i < 26; i++) if(data[i] % 4 != 0) ok = false;
	}
	else{
		int g1, g2, g4;
		if(x && y) g1 = 1, g2 = H/2 + W/2, g4 = (H/2) * (W/2);
		else{
			if(!x) swap(H, W);
			g1 = 0, g2 = W / 2, g4 = (H/2) * (W/2);
		}
		int num = 0;
		for(int j = 0; j < 26; j++){
			if(data[j] % 2 == 1) {data[j]--; num++;};
			if(num == g1) break;
		}
		num = 0;
		for(int j = 0; j < 26; j++){
			while(data[j] >= 4) { data[j] -= 4; num++;}; 
			if(num == g4) break;
		}
		num = 0;
		for(int j = 0; j < 26; j++){
			while(data[j] >= 2) {data[j] -= 2; num++;};
			if(num == g2) break;
		}
		for(int i = 0; i < 26; i++){
			if(data[i]) ok = false;
		}
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}
	