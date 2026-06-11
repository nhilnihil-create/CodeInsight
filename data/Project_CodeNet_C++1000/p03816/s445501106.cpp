#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define inf LLONG_MAX>>2
#define MAX 1000000
#define mod 1000000007
#define pb push_back
#define f(i,a,n,x) for ((i)=(a);(i)<(n);(i)+=(x))
#define fd(i,a,n,x) for ((i)=(a);(i)>=(n);(i)-=(x))
#define fi first
#define se second
#define mk make_pair
#define pi pair
#define vt vector
using namespace std;
void read(vt<ll> &a,ll n){ll i,temp;f(i,0,n,1){cin>>temp;a.pb(temp);}}
void solve(){
    ll n,x;
    vt<ll> a;
    cin>>n;
    read(a,n);
    sort(a.begin(),a.end());
    x=unique(a.begin(),a.end())-a.begin();
    cout<<(x-!(x&1))<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}