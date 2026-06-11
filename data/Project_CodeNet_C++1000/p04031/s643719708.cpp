#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    ll sm=0;
    ll sm2=0;
    rep(i,n){
        sm+=a[i];
        sm2+=a[i]*a[i];
    }
    ll ans=sm2;
    int mn2;
    double mn=(double)sm/(double)n;
    if(mn>=0){
        mn+=0.5;
        mn2=mn;
    } else{
        mn*=-1;
        mn+=0.5;
        mn2=mn;
        mn2*=-1;
    }
    ans+=n*mn2*mn2;
    ans-=2*mn2*sm;
    cout << ans << endl;
}