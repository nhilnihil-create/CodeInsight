#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;



int main(){
    ll n;
    cin >> n;
    ll a[n];
    ll res=0;
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    for(ll i=0;i<n-1;i++){
        if(a[i]%2==0){
            res+=a[i]/2;
        }
        else{
            res+=a[i]/2;
            if(a[i+1]>0){
                res++;
                a[i+1]--;
            }
        }
    }
    res+=a[n-1]/2;
    cout << res << endl;
    return 0;
}  
