#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int count(ll n){
    int digits=0;
    while(n){
        n/=10;
        digits++;
    }
    return digits;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ll N;
    cin>>N;

    int ans=12;

    for(ll i=1ll;i*i<=N;i++){
        if(N%i !=0) continue;

        int cur=max(count(i),count(N/i));

        if(ans>cur){
            ans=cur;
        }
    }
    cout<<ans<<endl;

}
