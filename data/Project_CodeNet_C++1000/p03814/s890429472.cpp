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
	int he, ta;
	REP(i,s.size()){
		if(s[i] == 'A'){
			he = i;
			break;
		}
	}
	for(int i = s.size()-1; i >= 0; i--){
		if(s[i] == 'Z'){
			ta = i;
			break;
		}
	}
	cout << ta-he+1 << endl;
}