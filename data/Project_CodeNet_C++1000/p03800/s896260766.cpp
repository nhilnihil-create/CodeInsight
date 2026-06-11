#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 112345;

int n;
string s;
bool possible = false;
int v[MAXN];
int ans[MAXN];

inline bool query(int pos){
	if(v[pos] == 0) return (s[pos] == 'o'); // sheep
	return (s[pos] != 'o'); // wolf
}

void solve(int test){
	
	bool failed = false;
	
	for(int i = 0 ; i < n ; i ++){
		
		int prev = (i ? i - 1 : n - 1);
		int nxt = (i == n - 1 ? 0 : i + 1);
		
		if(query(i)){
			
			if(v[prev] != -1 && v[nxt] != -1){
				if(v[prev] != v[nxt]){
					failed = true;
					break;
				}
			} else if(v[prev] != -1){
				v[nxt] = v[prev];
			} else if(v[nxt] != -1){
				v[prev] = v[nxt];
			} else {
				v[prev] = v[nxt] = test;
			}
			
		} else {
			
			if(v[prev] != -1 && v[nxt] != -1){
				if(v[prev] == v[nxt]){
					failed = true;
					break;
				}
			} else if(v[prev] != -1){
				v[nxt] = v[prev] ^ 1;
			} else if(v[nxt] != -1){
				v[prev] = v[nxt] ^ 1;
			} else {
				v[prev] = test;
				v[nxt] = test ^ 1;
			}
		}
	}
	
	if(!failed){
	//	cout << "success ";
	//	cout << test << "\n";
		possible = true;
		for(int i = 0 ; i < n ; i ++)
			ans[i] = v[i];
		
	}
	
	return;
}

int main(){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	cin >> s;
	
	// assume first position is sheep
	memset(v, -1, sizeof v);
	v[0] = 0;
	solve(0);
	
	memset(v, -1, sizeof v);
	v[0] = 0;
	solve(1);
	
	// assume first position is wolf
	memset(v, -1, sizeof v);
	v[0] = 1;
	solve(0);
	
	memset(v, -1, sizeof v);
	v[0] = 1;
	solve(1);
	
	if(!possible){
		cout << "-1\n";
		return 0;
	}
	
	for(int i = 0 ; i < n ; i ++){
		if(ans[i] == 0) cout << "S";
		else cout << "W";
	}
	
	cout << "\n";
	
	return 0;
}