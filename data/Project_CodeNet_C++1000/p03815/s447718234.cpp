#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,ans;
signed main(){
	cin>>x;
	ans=x/11*2;
	if(x%11>6) ans+=2;
	else if(x%11) ans++;
	cout<<ans;
	return 0;
}