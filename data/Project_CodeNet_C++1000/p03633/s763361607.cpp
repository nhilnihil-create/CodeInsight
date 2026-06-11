#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int n;
ll a[N];
ll gcd(ll a,ll b){
	return !b?a:gcd(b,a%b);
}
int main(){
	cin>>n;
	ll g=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g=g/gcd(g,a[i])*a[i];
	} 
	cout<<g<<endl;
	return 0;
}