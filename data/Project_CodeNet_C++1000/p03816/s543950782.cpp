#include <bits/stdc++.h>
using  namespace std;
typedef long long ll;
#define RAP(i, n) for(ll i=0;i<(n);i++)
#define FOR(i, a, b) for(ll i=(a);i<(b);i++)

int main(){
    ll n, a, count2=0;
    cin >> n;
    map<ll,ll> A;
    RAP(i, n){
        cin >> a;
        A[a]++;
    }
    for(auto itr=A.begin();itr!=A.end();itr++){
        if(itr->second==2){
            count2++;
        }else if(itr->second>1){
            while(1){
                n -= 2;
                itr->second -= 2;
                if(itr->second==1){
                    break;
                }else if(itr->second==2){
                    count2++;
                  	break;
                }
            }
        }
    }
    for(ll i=count2;i>0;i-=2){
        n -= 2;
    }
   
    cout << n << endl;
    return 0;
}
