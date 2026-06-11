#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	string s;
	getline(cin,s);
	int n=s.size()-2;
	printf("%c%d%c",s[0],n,s.back());
	return 0;
}


