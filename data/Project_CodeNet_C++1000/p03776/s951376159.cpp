#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=55;
ll ncr[55][55];
void init(){
    for(ll i=0;i<N;i++){
        for(ll j=0;j<=i;j++){
            if(j==0 || j==i)ncr[i][j]=1;
            else ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
        }
    }
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    ll n,A,B;cin>>n>>A>>B;
    ll a[n];for(ll i=0;i<n;i++)cin>>a[i];
    sort(a,a+n,greater<ll>());
    long double avg=0;for(ll i=0;i<A;i++)avg+=a[i];
    avg/=(A*1.0);
    ll tot=0,req=0;
    for(ll i=0;i<n;i++){
        if(a[i]!=a[A-1])continue;
        tot++;
        if(i<A)req++;
    }
    ll cnt=0;
    if(req==A)for(ll take=A;take<=B;take++)cnt+=ncr[tot][take];
    else cnt=ncr[tot][req];
    cout<<fixed<<setprecision(18)<<avg<<"\n";
    cout<<cnt;
}
