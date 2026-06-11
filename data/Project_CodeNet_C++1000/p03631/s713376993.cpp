#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string n,m; cin>>n;
	m=n;
	reverse(n.begin(),n.end());
	if(n==m) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}