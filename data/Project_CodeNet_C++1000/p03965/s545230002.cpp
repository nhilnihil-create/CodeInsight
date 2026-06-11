#include<bits/stdc++.h>
#define LL long long
#define F(x,y,z) for(int x=y;x<=z;++x)
#define D(x,y,z) for(int x=y;x>=z;--x)
using namespace std;
string s;
int main(){
	cin>>s;
	int k=0,ans=0;
	for(auto i:s){
		ans+=k;
		ans-=i=='p';
		k^=1;
	}
	cout<<ans<<'\n';
	return 0;
}