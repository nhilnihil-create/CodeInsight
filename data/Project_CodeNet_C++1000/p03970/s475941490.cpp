#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;


main(){
	string s;
	string t="CODEFESTIVAL2016";
	cin >> s;

	int ans=0;
	for(int i=0;i<s.length();i++){
		if(s[i]!=t[i]) ans++;
	}
	cout << ans << endl;

	return 0;
}
