#include <bits/stdc++.h>

#define mod 1000000007

using namespace std;
typedef long long ll; 
 
int main(void){
	
	string s;
	
	cin >> s;
	
	if((s.length() % 2 == 0 && !(s[0] == s[s.length()-1])) || (!(s.length() % 2 == 0) && s[0] == s[s.length()-1]))
		cout << "Second";
	else
		cout << "First";
	
	return 0;
}