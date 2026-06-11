#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	int a,b,c,d,n;
	cin>>a>>b>>c>>d>>n;
	int minv=min(min(a*4,b*2),c);
	if(minv*2<=d){
		cout<<minv*n;
	}
	else{
		cout<<(n%2)*minv+n/2*d;
	}
	return 0;
}
