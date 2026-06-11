#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
	string s;cin>>s;
	int l=s.size();
	bool chk=0;
	for(int i=0;i<l/2;i++){
		if(s[i]=='d'&&s[l-i-1]=='b') chk=1;
		else if(s[i]=='b'&&s[l-i-1]=='d') chk=1;
		else if(s[i]=='q'&&s[l-i-1]=='p') chk=1;
		else if(s[i]=='p'&&s[l-i-1]=='q') chk=1;
		else {
			chk=0;
			break;
		}
	}
	if(l%2==1) chk=0;
	if(chk) cout<<"Yes"<<"\n";
	else cout<<"No"<<"\n";
} 
