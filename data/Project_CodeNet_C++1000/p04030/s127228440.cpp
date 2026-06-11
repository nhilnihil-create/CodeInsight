#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//container util
#define SORT(c) sort((c).begin(),(c).end())
#define all(a) (a).begin(), (a).end()

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//print
#define pv(val) cerr << #val << '=' << (val) << endl

const int INF = 1e9;

int main(void){

	string s; cin >> s;

	string ans;

	REP(i,s.length()){
		if(s[i] == '0') ans += '0';
		else if(s[i] == '1') ans += '1';
		else{
			int N = ans.length();
			if(N == 0) continue;
			else{
				ans = ans.erase(N-1);
			}
		}

	}

	cout << ans << endl;

	return 0;

}
