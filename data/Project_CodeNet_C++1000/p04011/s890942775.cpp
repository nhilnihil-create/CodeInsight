#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n,k,x,y;
	cin>>n>>k>>x>>y;
	if(min(n,k)==n){
		cout<<n*x;
		return 0;
	}
	cout<<(k*x)+(n-k)*y;
    return 0;
}