#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	string s;
	cin >> s;

	int ans = 0;
	for(int i=1; i<(int)s.size(); i++){
		if(s[i-1] != s[i])ans++;
	}
	cout << ans << endl;

	return 0;
}

