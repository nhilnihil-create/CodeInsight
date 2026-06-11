#include <bits/stdc++.h>

using namespace std;


int main(){
	string a, b;
	cin >> a >> b;
	if(a.length() > b.length()) cout << "GREATER";
	else if(a.length() < b.length()) cout << "LESS";
	else{
		if(a<b) cout << "LESS";
		else if(a==b) cout << "EQUAL";
		else if(a>b) cout << "GREATER";
	}
	return 0;
}

