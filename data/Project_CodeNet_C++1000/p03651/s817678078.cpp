#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int gcd(int a,int b){
	if(a<b) return gcd(b,a);
	int r;
	while(r=a%b){
		a=b;
		b=r;
	}
	return b;
}

int main(){
	int n,k;cin>>n>>k;
	int a[n];
	rep(i,n) cin>>a[i];
	sort(a,a+n);
	int g=a[0];
	rep(i,n) g=gcd(g,a[i]);

	if(k%g==0&&k<=a[n-1]) cout<<"POSSIBLE"<<"\n";
	else cout<<"IMPOSSIBLE"<<"\n";
}