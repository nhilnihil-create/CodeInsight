#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string s;
	cin>>s;
	ll n=s.size()-2;
	bool ch=false;
	if(s[0]==s[s.size()-1]){
		ch=true;
	}
	if(ch){
		cout << (n%2!=0?"Second":"First");
	}
	else{
		cout << (n%2!=0?"First":"Second");
	}
	// your code goes here
	return 0;
}