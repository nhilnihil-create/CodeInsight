#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int N, L;

int main(void){
	cin >> N >> L;
	vector<string> s(N);
	rep(i, N) cin >> s[i];
	sort(s.begin(), s.end());
	string ans = "";
	rep(i, N) ans+=s[i];
	cout << ans << endl;
	return 0;
}
