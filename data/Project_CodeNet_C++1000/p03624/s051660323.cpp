#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string s;

int main(void){
	cin >> s;
	vector<int> c(30);
	rep(i, s.size()) c[s[i]-'a']++;
	char ans = '#';
	rep(i, 26) if(c[i] == 0){
		ans = 'a'+i;
		break;
	}
	if(ans == '#') cout << "None" << endl;
	else cout << ans << endl;
	return 0;
}
