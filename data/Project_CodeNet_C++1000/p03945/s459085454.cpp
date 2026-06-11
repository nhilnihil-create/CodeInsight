#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string s;

int main(void){
	cin >> s;
	lli ans = 0;
	rep(i, s.size()-1){
		if(s[i] != s[i+1]) ans++;
	}
	cout << ans << endl;
	return 0;
}
