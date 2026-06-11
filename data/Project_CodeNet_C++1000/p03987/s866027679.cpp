#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=2e5+5;
ll n,ans,a[N],lft[N],rgt[N];
stack<ll>stk;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    stk.push(0);
    for(ll i=1;i<=n;i++){
        while(a[stk.top()]>a[i])stk.pop();
        lft[i]=stk.top();
        stk.push(i);
    }
    while(!stk.empty())stk.pop();
    stk.push(n+1);
    for(ll i=n;i>=1;i--){
        while(a[stk.top()]>a[i])stk.pop();
        rgt[i]=stk.top();
        stk.push(i);
    }
    for(ll i=1;i<=n;i++)ans+=a[i]*(i-lft[i])*(rgt[i]-i);
    cout<<ans;
}

