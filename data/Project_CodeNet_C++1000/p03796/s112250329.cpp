#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

const lli mod = 1e9+7;
lli n;

lli mod_fact(lli x){
	if(x == 0) return 1;
	return (x*mod_fact(x-1))%mod;
}

int main(void){
	cin >> n;
	cout << mod_fact(n) << endl;
	return 0;
}
