#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	string s;
	cin >> s;
	rep(i,4){
		cout << s[i];
	}
	cout << " ";
	for (int i = 4; i < s.size(); ++i) {
		cout << s[i];
	}
	cout << endl;
    return 0;
}