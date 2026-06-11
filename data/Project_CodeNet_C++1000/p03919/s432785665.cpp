#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
typedef long long ll; typedef long double ld;
using namespace std;
const int INF=1e9, MOD=1e9+7;
const int MAX_N=10000;
int h,w;
string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> h >> w;
	REP(i,1,h+1) REP(j,0,w){
		cin >> s;
		if(s=="snuke"){
			cout << (char)('A'+j) << i << endl;
			return 0;
		}
	}
	
	return 0;
}
