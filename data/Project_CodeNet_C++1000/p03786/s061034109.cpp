// i hope i get better                                                           
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int sz=1e5+9;
int n;
pll a[sz];
int ans;
ll cs[sz];

int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i].f;
		a[i].s=i;
	}
	sort(a,a+n);
	cs[0]=a[0].f;
	for(int i=1;i<n;++i){
		cs[i]=cs[i-1]+a[i].f;
	}
	ans=1;
	for(int i=n-2;i>=0;--i){
		if(a[i+1].f<=2*cs[i]) ans++;
		else break;
	}
	cout<<ans;
	return 0;
}