#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
signed main(void){
    int n; cin>>n;
    vector <int> p(n); 
    rep(i,n) cin>>p[i];
    vector <int> a(n);
    vector <int> b(n);
    a[0] = 20000;
    rep(i,n){
        if(i==0) continue;
        a[i] = a[i-1] + 20000;
    }
    b[n-1] = 20000;
    rrep(i,n){
        if(i==n-1) continue;
        b[i] = b[i+1] + 20000;
    }
    
    rep(i,n){
        a[p[i]-1] += i;
    }
    rep(i,n) cout<<a[i]<<' ';
    cout<<endl;
    rep(o,n) cout<<b[o]<<' ';
}
