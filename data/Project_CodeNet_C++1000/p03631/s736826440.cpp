#include <bits/stdc++.h>

using namespace std;

#define ll long long

string rev(string s) {
	reverse(s.begin(),s.end());
	return s;
}
int main(){
	string s;
	getline(cin,s);
	int n1=stoi(s);
	int n2=stoi(rev(s));
	if(n1==n2) puts("Yes");
	else puts("No");
	return 0;
}


