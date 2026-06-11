#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n,i;
    cin >> n;
    vector <ll> a(n),b(n),c(n),d(n+1);
    d[n]=0;
    
    rep(i,n){
        cin >> a[i] >> b[i];
    }
    
    
    for (int i=n-1; i>=0 ; --i){
        if ((a[i]+d[i+1])%b[i]==0){
            d[i]=d[i+1];
        }
        else{
        d[i]=b[i]-a[i];
        if (d[i+1]> d[i]){
            d[i]+=((a[i]+d[i+1])/b[i])*b[i];
            

        }
        }

    }

    cout << d[0] << endl;
    

    return 0;
}