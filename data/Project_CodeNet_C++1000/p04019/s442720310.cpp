#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
	bool ncounts = false;
	bool wcounts = false;
	bool scounts = false;
	bool ecounts = false;
	rep(i,(int)s.size()){
		if(s[i] == 'N') ncounts = true;
		else if(s[i] == 'W') wcounts = true;
		else if(s[i] == 'S') scounts = true;
		else if(s[i] == 'E') ecounts = true;
	}
	if(ncounts && !scounts) cout << "No" << endl;
	else if(scounts && !ncounts) cout << "No" << endl;
	else if(ecounts && !wcounts) cout << "No" << endl;
	else if(wcounts && !ecounts) cout << "No" << endl;
	else cout << "Yes" << endl;
}