#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
int main(void){
    ll n,t;
    cin>>n>>t;
    ll a[100000];
    for(int i=0;i<n;i++) cin>>a[i];
    ll nowMIN=a[0];
    map<ll,ll> m;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            m[a[i-1]-nowMIN]++;
            nowMIN=min(nowMIN,a[i]);
        }
        else if(i==n-1) m[a[i]-nowMIN]++;
    }
    ll MAX=-1;
    for(auto itr=m.begin();itr!=m.end();itr++){
        MAX=max(MAX,itr->first);
    }
    cout<<m[MAX]<<endl;
}