#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod ll(1e9+7)
void solve(){
	ll a,b;
	char op;
	cin>>a>>op>>b;
	if(op=='-'){
		cout<<a-b<<endl;
	}
	else{
		cout<<a+b<<endl;
	}
}


int main(){
	solve();
}