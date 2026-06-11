#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define ll long long
using namespace std;
signed main(){
	string s;
	cin>>s;
	int a=0;
	if(s[0] == s[s.size()-1])a++;
	if( a != s.size()%2 ){cout<<"First"<<endl;}
	else cout<<"Second"<<endl;
	return 0;
}