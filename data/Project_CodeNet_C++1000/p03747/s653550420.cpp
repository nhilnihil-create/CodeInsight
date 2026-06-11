#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MX=100010, inf=2e9;

ll n, l, t;
ll X[MX];
ll cnt;

ll norm(ll x, ll r){
    if(x>=0) return x%r;
    return (r-abs(x)%r)%r;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>l>>t;
    for(int i=1; i<=n; i++){
        ll x, w;
        cin>>x>>w;
        if(w==1){
            cnt+=(x+t)/l;
            X[i]=(x+t)%l;
        }
        else{
            if(x-t<0)
                cnt-=(abs(x-t)+l-1)/l;
            X[i]=(x-t + (t + l-t%l))%l;
        }
    }
    sort(X+1, X+n+1);
    cnt=norm(cnt, n);
    for(int i=1+cnt; i<=n+cnt; i++){
        int j=(i-1)%n+1;
        cout<<X[j]<<'\n';
    }
    return 0;
}