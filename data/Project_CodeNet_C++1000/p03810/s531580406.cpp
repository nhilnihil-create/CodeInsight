#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e5+5;
ll n,a[N];
bool solve(){
    ll even=0,ones=0;
    for(ll i=0;i<n;i++){
        if(a[i]%2==0)even++;
        if(a[i]==1)ones++;
    }

    if(even&1)return 1;
    if(even<n-1 || ones>0)return 0;

    ll g=0;
    for(ll i=0;i<n;i++){
        if(a[i]&1)a[i]--;
        g=__gcd(g,a[i]);
    }
    for(ll i=0;i<n;i++)
        a[i]/=g;
    return solve()^1;
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(ll i=0;i<n;i++)cin>>a[i];
    cout<<(solve()?"First\n":"Second\n");
}