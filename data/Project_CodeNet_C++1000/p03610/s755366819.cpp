#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
typedef long long ll;

int main(){
	string s;
	cin >> s;
	
	vector<char> ans;
	for(int i=0; i<s.size(); i+=2){
		ans.push_back(s[i]);
	}
	REP(i,ans.size()) cout << ans[i];
	cout << endl;
	
	return 0;
}