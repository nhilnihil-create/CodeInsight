#include <bits/stdc++.h>
//#include <iostream>
//#include <cstdio>

#define repl(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repl(i, 0, n)
#define MOD 1000000007
#define INF 2000000000

typedef long long ll;
typedef unsigned long long ull;
//typedef Pair<int,int> P;

using namespace std;

int main(void){
	string s;
	cin>>s;
	rep(i,s.size()){
		if(s[i]=='b' && s[s.size()-1-i]!='d'
			|| s[i]=='d' && s[s.size()-1-i]!='b'
			|| s[i]=='q' && s[s.size()-1-i]!='p'
			|| s[i]=='p' && s[s.size()-1-i]!='q'){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	
	return 0;
}