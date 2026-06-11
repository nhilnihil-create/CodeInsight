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
ll a[100017];
void solve(){
	ll n,su,cur,i;
	cin>>n;
	take(a,n);
	sort(a,a+n);
	su=a[0];
	cur=1;
	for(i=1;i<n;i++){
		if(su*2 >= a[i]){
			cur++;
			su+=a[i];
		}
		else{
//			cout<<su<<" "<<a[i]<<endl;
			su+=a[i];
			cur=1;
		}
	}
	cout<<cur;
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