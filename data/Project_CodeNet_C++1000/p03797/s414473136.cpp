#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n,m,ans;
	cin>>n>>m;
	if(n*2<=m) cout<<n+(m-n*2)/4<<endl;
	else cout<<m/2<<endl;
	return 0;
}