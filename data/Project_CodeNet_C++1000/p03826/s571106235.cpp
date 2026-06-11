#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int a,b,c,d; cin>>a>>b>>c>>d;
	if(a*b>c*d) cout<<a*b<<endl;
	else if(a*b<c*d) cout<<c*d<<endl;
	else cout<<a*b<<endl;
}