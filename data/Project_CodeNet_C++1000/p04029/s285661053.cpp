#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	int ans=0;
	rep(i,n+1) ans+=i;
	cout<<ans<<endl;
}