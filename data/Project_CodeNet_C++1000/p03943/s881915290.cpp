#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int a,b,c; cin>>a>>b>>c;
	if(a==b+c) cout<<"Yes"<<endl;
	else if(b==a+c) cout<<"Yes"<<endl;
	else if(c==a+b) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}