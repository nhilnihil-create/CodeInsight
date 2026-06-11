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
	int ans = 0;
	int tmp;
	string s;
	cin >> s;
	set<char> se;
	REP(i, s.size()){
		se.insert(s[i]);
	}
	if (se.size() == s.size()) cout << "yes" << endl;
	else cout << "no" << endl;
	
//	cout << ans << endl;
}