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
    ll n,i,ans;
    bool flag;
    string s1,s2;
    cin>>n>>s1>>s2;
    if (s1[0]==s2[0]){
        ans=3;
        i=1;
        flag=true;
    }
    else{
        ans=6;
        i=2;
        flag=false;
    }
    for (;i<n;)
        if (flag && s1[i]==s2[i]){
            ans=(ans*2)%mod;
            flag=true;
            i++;
        }
        else if (flag && s1[i]==s1[i+1]){
            ans=(ans*2)%mod;
            flag=false;
            i+=2;
        }
        else if (s1[i]==s2[i]){
            flag=true;
            i++;
        }
        else{
            flag=false;
            ans=(ans*3)%mod;
            i+=2;
        }
    cout<<ans<<endl;
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