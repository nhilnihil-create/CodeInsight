#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main(){
    int n,k; cin >> n >> k;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ll ans=1e18;
    for(int i=0;i<(1<<n);i++){
        if(__builtin_popcount(i)>=k){
            ll cnt=0;
            ll ma=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    if(ma<a[j])ma=a[j];
                    else{
                        cnt+=ma+1-a[j];
                        ma++;
                    }
                }
                else{
                    ma=max(ma,a[j]);
                }
            }
            ans=min(ans,cnt);
        }
    }
    cout << ans << endl;
}