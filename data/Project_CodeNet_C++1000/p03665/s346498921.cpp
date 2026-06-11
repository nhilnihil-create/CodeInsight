#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#include <numeric>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[8]={ 0, 1, 0,-1, 1, 1,-1,-1}; // x軸方向への変位
ll dy[8]={ 1, 0,-1, 0, 1,-1, 1,-1}; // y軸方向への変位

ll comb(ll n, ll r){
    ll child = 1, mother = 1;
    if(r<n/2){
        for(ll i = 1; i <= r; i++){
            ll a = n-i+1, b = i;
            child = child * a;
            mother = mother * b;
            //cout << child << " " << mother << endl;
            if(child%mother==0){
                child /= mother;
                mother = 1;
            }
        }
    }
    else if(r>=n/2){
        for(ll i = 1; i <= n-r; i++){
            ll a = n-i+1, b = i;
            child = child * a;
            mother = mother * b;
            //cout << child << " " << mother << endl;
            if(child%mother==0){
                child /= mother;
                mother = 1;
            }
        }
    }
    ll ans = child / mother;
    return ans;
}

int main(void){
    ll n, p;
    cin >> n >> p;
    ll a = 0, b = 0;
    for(ll i = 0; i < n; i++){
        ll c;
        cin >> c;
        if(c%2==0) a++;
        else b++;
    }
    //cout << a << " " << b << endl;
    ll ans = 0;
    if(p==1){
        for(ll i = 1; i <= b; i+=2){
            for(ll j = 0; j <= a; j++){
                ans+=comb(b, i)*comb(a, j);
                //cout << i << " " << j  << " " << comb(b,i) << " " << comb(a, j) << endl;
            }
        }
    }
    if(p==0){
        for(ll i = 0; i <= a; i++)
            for(ll j = 0; j <= b; j+=2)
                ans+=comb(a, i)*comb(b, j);
    }
    cout << ans << endl;
    //cout << comb(50, 25) << endl;
    return 0;
}
