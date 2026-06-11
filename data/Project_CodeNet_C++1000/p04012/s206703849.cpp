#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	map<char, int> M;
	int i;
	bool ok = true;
	int l = s.length();
	for(i=0; i<l; i++){
		M[s[i]]++;
	}
	for(auto it = M.begin(); it!=M.end(); it++){
		if((it->second)&1){
			ok = false;
			break;
		}
	}
	if(ok) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
