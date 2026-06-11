#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int main(){
	string s, ans;
	cin >> s;
	rep(i,s.size()){
		if(i%2==1) continue;
		else ans.push_back(s[i]);
	}
	cout << ans << endl;

	return 0;
}