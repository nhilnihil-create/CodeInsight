#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll mod = 1000000007;
    ll N;
    cin >> N;
    vector<ll> v;
    map<ll,ll> mp;
    rep(i,N){
        ll A;
        cin >> A;
        if(mp.count(A)) mp[A]++;
        else{
            mp.emplace(A,1);
            v.push_back(A);
        }
    }
    ll out = 0;
    bool isExist = true;
    sort(v.begin(),v.end());
    rep(i,v.size()){
        if(i==0){
            if(N%2==1){
                if(v[i]==0&&mp[v[i]]==1) ;
                else{
                    isExist = false;
                    break;
                }
            }else{
                if(v[i]==1&&mp[v[i]]==2) ;
                else{
                    isExist = false;
                    break;
                }
            }
        }else{
            if(v[i]==v[i-1]+2&&mp[v[i]]==2) ;
            else{
                isExist = false;
                break;
            }
        }
    }
    if(isExist){
        out = 1;
        rep(i,N/2){
            out = (out*2)%mod;
        }
    }
    cout << out << endl;
    return 0;
}
