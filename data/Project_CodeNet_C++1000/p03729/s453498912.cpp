#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string a,b,c; cin>>a>>b>>c;
	int ak=a.size();
	int bk=b.size();
	if(a[ak-1]==b[0]&&b[bk-1]==c[0]) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}