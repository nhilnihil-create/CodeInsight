//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF INT_MAX
#define LLINF LLONG_MAX
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
    for (T& x: vec) { is >> x; }
    return is;
}

int main() {
	string ans = "";
	ll tmp;
	//int n; cin >> n;
	string s; cin>>s;
	REP(i, s.size()){
		if(s[i] == '0') ans += "0";
		else if(s[i] == '1') ans += "1";
		else ans = ans.substr(0, ans.size()-1);
	}
	cout << ans << endl;
}