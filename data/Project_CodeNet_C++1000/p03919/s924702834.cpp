#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(ll I = int(A); I < int(B); ++I)
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll H,W;
	cin >> H >> W;
	string s;
	FOR(i,0,H){
		FOR(j,0,W){
			cin >> s;
			if(s=="snuke"){
				cout << char('A'+j) << i+1 << endl;
			}
		}
	}
}