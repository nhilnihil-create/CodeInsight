#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9+7;

int main(){
	string s;
	cin >> s;

	int ans=0;
	int half=(s.size()+1)/2;
	for(int i=0;i<half;i++){
		if(s.at(i)=='p')	ans--;
	}
	for(int i=half;i<s.size();i++){
		if(s.at(i)=='g')	ans++;
	}
	cout << ans << endl;
	
	return 0;
}
