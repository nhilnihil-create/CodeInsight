#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	int count = 0;
	rep(i,n){
		if(s[i] == 'I') count++;
		if(s[i] == 'D') count--;
		ans = max(ans, count);
	}
	cout << ans << endl;
    return 0;
}

