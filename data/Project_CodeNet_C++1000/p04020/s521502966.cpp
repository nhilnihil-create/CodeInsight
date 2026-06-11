#include<bits/stdc++.h>
using namespace std;
long long n,m,a,last,ans;
signed main(){
	cin>>n;
	while(n--){
		cin>>a;
		if(last&&a)ans++,a--;
		ans+=a/2;
		last=a%2;
	}cout<<ans;
}