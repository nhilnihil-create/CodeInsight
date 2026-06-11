#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main (){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ll ans = 0;
    ll m=2;
    ans += a[0]-1;
    for(int i=1;i<n;i++){
        if(m!=a[i]){
            ans+=a[i]/m;
            if(a[i]%m==0){
                ans -= 1;
            }
        }else{
            m++;
        }
    }
    cout<<ans<<endl;
    return 0;
}