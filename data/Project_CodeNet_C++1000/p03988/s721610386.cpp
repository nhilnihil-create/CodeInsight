#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=2e5+5;
ll n,d,a[105];
multiset<ll> st;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(ll i=0;i<n;i++)cin>>a[i],d=max(d,a[i]),st.insert(a[i]);
    ll lowest=d+1;
    for(ll i=0;i<=d;i++){
        ll cur=max(i,d-i);
        if(!st.count(cur))return cout<<"Impossible" , 0;
        st.erase(st.find(cur));
        lowest=min(lowest,cur);
    }

    if(!st.empty() && (*st.begin())<=lowest)cout<<"Impossible" , 0;
    else cout<<"Possible" , 0;
}

