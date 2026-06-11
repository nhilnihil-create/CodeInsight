#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll llabs(ll x){
	if(x<0) return -x;
	else return x;
}

int main(){
	ll x,y;
	cin>>x>>y;
	if(llabs(x-y)<=1) cout<<"Brown\n";
	else cout<<"Alice\n";
}