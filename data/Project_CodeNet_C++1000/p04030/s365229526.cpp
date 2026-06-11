#include <bits/stdc++.h>
using namespace std;

int main(){
	string s, ans;
	cin >> s;
	for(int i=0; i<s.size(); i++){
		if(s.at(i)!='B'){
			ans+=s.at(i);
		}
		if(s.at(i)=='B'){
			if(ans.size()>0) ans.pop_back();
		}
	}
	cout << ans << endl;
}
