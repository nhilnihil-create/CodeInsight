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

	string S; cin >> S;
	int N = S.length();
	map<char, int> mp;	

	REP(i,N) mp[S[i]]++;

	char ans = ' ';
	for(char a = 'a';a<='z';a++){
		if(mp[a] == 0){
			ans = a;
			break;
		}
	}

	if(ans == ' ') cout << "None" << endl;
	else cout << ans << endl;

	return 0;

}
