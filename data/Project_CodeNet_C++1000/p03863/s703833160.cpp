#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	bool flag=(s[0]==s[s.size()-1]);
	if(s.size()%2==1)flag=!flag;
	
	if(flag)cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}