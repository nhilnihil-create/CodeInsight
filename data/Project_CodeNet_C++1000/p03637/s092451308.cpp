#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(ll i=0;i<(ll)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
const ll mod=1e9+7;
const ll INF = 1e9;

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b); 
}

bool is_prime(ll x){
    if(x==1) return false;
    for(ll i=2; i*i<=x;i++){
        if(x%i == 0) return false;
    }
    return true;
}

int main(){
    fast_io
    
    int n;
    cin>>n;
    vector<ll> a(n);
    vector<int> cnt(3);
    rep(i,n) cin>>a[i];

    rep(i,n){
        if(a[i]%4==0) cnt[0]++;
        else if(a[i]%4%2) cnt[1]++;
        else cnt[2]++;
    }
    if(cnt[0]+cnt[1] == n && cnt[0]+1 == cnt[1]){
        cout<<"Yes"<<endl;
        return 0;
    }
    if(cnt[0]<cnt[1]) {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    return 0;
}