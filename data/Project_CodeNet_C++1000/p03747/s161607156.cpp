#include <bits/stdc++.h>
using namespace std;
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
#define mod 1000000007

ll gcd(ll x,ll y) {return y ? gcd(y,x%y) : x;} 
ll lcm(ll x,ll y) {return x/gcd(x,y)*y;}

int main(){
    ll n,l,t,cnt=0;
    cin >> n >> l >> t;
    vector<pair<ll,ll>> a(n);
    vector<ll> b(n);
    rep(i,n) cin >> a[i].first >> a[i].second;
    rep(i,n){
        b[i]=(((a[i].first+(a[i].second==1?1:-1)*t)%l)+l)%l;
    }
    ll now=b[0];
    sort(b.begin(),b.end());
    if(a[0].second==1){
        for(int i=1;i<n;i++){
            if(a[i].second==2){
                ll sa=a[i].first-a[0].first;
                ll si=2*t-sa-1;
                if(si>=0){
                    cnt+=si/l+1;
                }
            }
        }
        int su=cnt%n;
        int se=find(b.begin(),b.end(),now)-b.begin();
        rotate(b.begin(),b.begin()+(se-su+n)%n,b.end());
    }else{
        for(int i=1;i<n;i++){
            if(a[i].second==1){
                ll sa=(a[0].first+l)-a[i].first;
                ll si=2*t-sa;
                if(si>=0){
                    cnt+=si/l+1;
                }
            }
        }
        int su=cnt%n;
        int se=find(b.begin(),b.end(),now)-b.begin();
        rotate(b.begin(),b.begin()+(se+su+n)%n,b.end());
    }
    
    for(int i=0;i<n;i++){
        cout << b[i] << endl;
    }
    
    return 0;
}









