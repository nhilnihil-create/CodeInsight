#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, L;
	cin >> N >> L;
	string S[N];
	rep(i,N) cin >> S[i];
	sort(S,S+N);
	string ans = "";
	rep(i,N) ans += S[i];
	cout << ans << endl;
	return 0;
}
