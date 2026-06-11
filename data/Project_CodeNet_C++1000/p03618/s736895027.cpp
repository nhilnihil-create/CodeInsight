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
	ll ans = 0;
	int tmp;
	string s;
	cin >> s;
	ll co[26] ={};
	ll n = s.size();
	ans = n * (n-1) /2 + 1;
	REP(i, n) co[s[i]-'a']++;
	REP(i, 26) ans -= co[i] * (co[i] -1)/2;
	cout << ans << endl;
}