#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int a,b; cin>>a>>b;
	int ans=a+b;
	if(ans>23) cout<<ans-24<<endl;
	else cout<<ans<<endl;
}