/*Arnab's Code
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define vll vector<ll>
#define vii vector<int>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define take(a,n) for(ll i=0;i<n;i++)cin>>a[i]
#define takes(a,n,st) for(ll i=st;i<n+st;i++)cin>>a[i]
ll sum(ll a[],ll n,ll s){ for(ll i=0;i<n;i++)s+=a[i]; return s;}
#define mod 1000000009
ll power(ll x, ll y, ll p)  {  
    ll res = 1;  
    x = x % p;   
    if (x == 0) return 0;  
    while (y > 0){  
        if (y & 1)  
            res = (res*x) % p;  
        y = y>>1;
        x = (x*x) % p;  
    }  
    return res;  
}
ll a[200017];
set< ll > s1,s2;
void solve(){
	ll n,i,x,tot,y;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>x;
		a[x]=i;
	}
	tot=0;
	s1.insert(0);
	s1.insert(n+1);
	s2.insert(0);
	s2.insert(0-n-1);
	for(i=1;i<=n;i++){
		s1.insert(a[i]);
		s2.insert(0-a[i]);
		x=*s1.upper_bound(a[i])-a[i];
		y=a[i]+*s2.upper_bound(0-a[i]);
//		cout<<x<<" "<<y<<endl;
		tot+=(x*y*i);		 
	}
	cout<<tot;
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ll t,T;
//	cin>>T;
	T=1;
	for(t=1;t<=T;t++){
//		cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}