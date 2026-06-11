#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main(){
#ifdef _DEBUG
	freopen("in" , "r", stdin );
	freopen("out", "w", stdout);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int n = s.size();
	int ans = 0, cnt = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'g'){
			if(cnt < n /2){
				cnt++;
				ans++;
			}
		} else {
			if(cnt >= n / 2) ans--;
			else cnt++;
		}
	}
	cout << ans << '\n';
}
