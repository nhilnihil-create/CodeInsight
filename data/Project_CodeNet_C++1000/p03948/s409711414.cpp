#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,t,mx,cnt,mn=(1ll<<30);
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>t;
    for(ll i=0,a;i<n;i++){
        cin>>a;
        mn=min(mn,a);
        if(a-mn>mx)mx=a-mn,cnt=1;
        else if(a-mn==mx)cnt++;
    }
    cout<<cnt;
}

