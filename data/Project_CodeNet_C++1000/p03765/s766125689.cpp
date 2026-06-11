#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 112345;

int qas[MAXN];
int qbs[MAXN];

int qat[MAXN];
int qbt[MAXN];

int main(){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	
	string s, t;
	cin >> s >> t;
	
	for(int i = 0 ; i < (int)s.size() ; i ++){
		
		if(i){
			qas[i] = qas[i - 1];
			qbs[i] = qbs[i - 1];
		}
		
		if(s[i] == 'A') qas[i]++;
		else qbs[i]++;
	}
	
	for(int i = 0 ; i < (int)t.size() ; i ++){
		
		if(i){
			qat[i] = qat[i - 1];
			qbt[i] = qbt[i - 1];
		}
		
		if(t[i] == 'A') qat[i]++;
		else qbt[i]++;
	}
	
	int q;
	cin >> q;
	while(q--){
		
		int ls, rs;
		int lt, rt;
		
		cin >> ls >> rs >> lt >> rt;
		--ls; --rs; --lt; --rt;
		
		int xs = qas[rs] - (ls ? qas[ls - 1] : 0);
		int ys = qbs[rs] - (ls ? qbs[ls - 1] : 0);
		
		int xt = qat[rt] - (lt ? qat[lt - 1] : 0);
		int yt = qbt[rt] - (lt ? qbt[lt - 1] : 0);
		
		int d0 = xs - ys;
		int d1 = -MOD, d2 = -MOD;
		if(ys > 0) d1 = d0 + 3;
		if(xs > 0) d2 = d0 - 3;
		
		int dt = xt - yt;
		
		int delta = d0 - dt;
		if((d0 - dt) % 3 == 0){
			cout << "YES\n";
			continue;
		}
		
		if((d1 != -MOD) && ((d1 - dt) % 3 == 0)){
			cout << "YES\n";
			continue;
		}
		
		if((d2 != -MOD) && ((d2 - dt) % 3 == 0)){
			cout << "YES\n";
			continue;
		}
		
		cout << "NO\n";
	}
	
	return 0;
}