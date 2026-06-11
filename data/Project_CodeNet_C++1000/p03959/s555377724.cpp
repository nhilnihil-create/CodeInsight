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
    vector <int> a(n); 
    vector <int> b(n); 
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    vector <int> kouho(n);
    int mae = -1;
    rep(i,n){
        if(mae <a[i]){
            //cout<<b[i]<<' '<<a[i]<<endl;
            if(b[i]<a[i]) {cout<<0<<endl; /*cout<<b[i]<<'!'<<a[i]<<endl;*/ return 0;}
            else kouho[i] = 1;
            mae = a[i];
        }else{
            kouho[i] = a[i];
        }
    }
    mae = -1;
    for(int i=n-1;i>=0;i--){
        
        if(mae < b[i]){
            
            if(a[i]<b[i]) {cout<<0<<endl; return 0;}
            else kouho[i] = 1;
            mae = b[i];
        }else{
            kouho[i] = min(kouho[i], b[i]);
        }
    }
    int ans = 1;
    rep(i,n){
        //cout<<kouho[i]<<endl;
        ans *= kouho[i];
        ans %= MOD;
    }
    cout<<ans<<endl;
}
