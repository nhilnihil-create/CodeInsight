#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string s; cin>>s;
	string r="CODEFESTIVAL2016";
	int cnt=0;
	rep(i,16) if(s[i]!=r[i]) cnt++;
	cout<<cnt<<endl;
}