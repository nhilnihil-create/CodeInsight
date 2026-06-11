#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n; cin>>n;
    vi a(n);
    rep(i,n)cin>>a[i];
    
    ll ansp=0, ansn=0;
    vi b = a;
    //a[0]を正にする
    rep(i,n){
        
        if(i!=0) b[i] += b[i-1];
        
        if(i%2==0){
            ansp += max(0, 1-b[i]);
            b[i]  = max(1, b[i]);
        }else{
            ansp += max(0, b[i]+1);
            b[i]  = min(-1, b[i]);
        }
    }
    
    rep(i,n){
        
        if(i!=0) a[i] += a[i-1];
        
        if(i%2!=0){
            ansn += max(0, 1-a[i]);
            a[i]  = max(1, a[i]);
        }else{
            ansn += max(0, a[i]+1);
            a[i]  = min(-1, a[i]);
        }
    }
    
    cout << min(ansp, ansn) << endl;
    
    
    return 0;
}