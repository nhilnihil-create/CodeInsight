#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define RREP(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long ll; typedef long double ld;
using namespace std;
const int INF=1e9, MOD=1e9+7;
int h,w;
string s;

int main(){
	cin >> h >> w;
	REP(i,1,h+1) for(char j='A';j<'A'+w;j++){{cin >> s; if(s=="snuke"){cout << j << i << endl; return 0;}}}
	
	return 0;
}
