//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	string ans = "";
	int tmp;
	string o, e;
	cin >> o >> e;
	REP(i, o.size()){
		ans += o[i];
		if(i < e.size()) ans+= e[i];
	}
	cout << ans << endl;
}
