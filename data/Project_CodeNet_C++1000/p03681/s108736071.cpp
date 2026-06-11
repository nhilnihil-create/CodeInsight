#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

const ll num = pow(10, 9) + 7;

ll func(ll a){
    ll val = 1;
    for(ll i = a; i > 0; i--){
        if(i == 1) val *= 1;
        else{
            val = (val * i) % num;
        }
    }
    return val;
}

int main(){
    ll N, M;
    cin >> N >> M;
    ll sub = abs(N - M);
    if(sub >= 2){
        cout << 0 << endl;
        return 0;
    }else{
        ll N_ans = func(N);
        ll M_ans = func(M);
        ll ans = (M_ans * N_ans) % num;
        if(sub == 0){
            ans = (ans * 2) % num;
        }
        cout << ans << endl;
        return 0;
    }
}