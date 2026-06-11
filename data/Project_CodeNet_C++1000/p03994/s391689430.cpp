#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

int main(){
	string s;
	int k;
	cin >> s >> k;
	
	for(int i = 0; i < s.size() - 1; ++i){
        if(s[i] == 'a') continue;
		if((26 - (int)(s[i] - 'a')) <= k){
			k -= 26 - (int)(s[i] - 'a');
			s[i] = 'a';
		}
	}
	if(k > 0){
		s[s.size() - 1] = (char)(((int)(s[s.size() - 1] - 'a') + k) % 26) + 'a';
	}
	
	cout << s << endl;
	return 0;
}

