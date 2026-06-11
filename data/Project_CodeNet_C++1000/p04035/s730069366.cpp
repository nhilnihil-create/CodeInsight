#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e5+5;
ll n,k,a[N];
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(ll i=1;i<=n;i++)cin>>a[i];

    for(ll i=1;i<n;i++){
        if(a[i]+a[i+1]>=k){
            cout<<"Possible\n";
            for(ll j=1;j<i;j++)cout<<j<<"\n";
            for(ll j=n-1;j>=i;j--)cout<<j<<"\n";
            return 0;
        }
    }
    cout<<"Impossible\n";
}

