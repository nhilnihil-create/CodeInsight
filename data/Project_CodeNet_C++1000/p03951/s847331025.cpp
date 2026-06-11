#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n;
	cin >> n;
	string s,t;
	cin >> s >> t;
	int count = n;
	string ans = "";
	rep(i,n){
		if(s.substr(i,n-i) == t.substr(0,n-i)){
			ans = s.substr(0,i) + t;
			cout << ans.size() << endl;
			return 0;
		}
	}
	cout << 2*n << endl;
    return 0;
}

