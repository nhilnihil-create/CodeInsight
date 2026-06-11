#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
using namespace std;
ll ma(ll a,ll b){
	if(a>b)return a;
	else return b;
}
int main(){
	int i,o,t,j,l,s,z;
	cin>>i>>o>>t>>j>>l>>s>>z;
	ll eff = 0;
	eff += o;
	eff += (i/2) *2;
	eff += (j/2) *2;
	eff += (l/2) *2;
	if(i%2 == 1 && j%2==1 && l%2==1)eff+=3;
	
	ll eff2 = 0;
	eff2 += o;
	eff2 += ( (i-1)/2 ) *2;
	eff2 += ( (j-1)/2 ) *2;
	eff2 += ( (l-1)/2 ) *2;
	if(i>0 && j>0 && l>0)eff2 += 3;
	cout<<ma(eff,eff2)<<endl;
	return 0;
}