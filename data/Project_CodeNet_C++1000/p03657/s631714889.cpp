#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int a,b;
	cin>>a>>b;
	if((a+b)%3==0 || a%3==0 || b%3==0) cout<<"Possible";
	else cout<<"Impossible";
	return 0;
}
