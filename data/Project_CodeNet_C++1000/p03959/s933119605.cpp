#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
const int MAX_N  = 100100;
const ll MOD = 1e9+7;

ll T[MAX_N];
ll A[MAX_N];
ll H[MAX_N];
int main(){
    int N;
    cin >> N;
    REP(i,N){
        ll t;
        cin >> t;
        T[i] = t;
    }
    REP(i,N){
        ll a;
        cin >> a;
        A[i] = a;
    }

    bool valid = true;
    ll last = T[0];
    H[0] = T[0];
    for(int i = 1; i < N; i++){
        ll h = T[i];
        if(h > last) H[i] = h;
        last = h;
    }

    last = A[N-1];
    if(H[N-1] != 0 && H[N-1] != A[N-1]) valid = false;
    else H[N-1] = A[N-1];
    for(int i = N-2; i >= 0; i--){
        ll h = A[i];
        //if(h > last){
        //    if(H[i] != 0 && H[i] != h) valid = false;
        //    else H[i] = h;
        //}
        if(H[i] > 0){
            if(h < H[i]) valid = false;
            if(h > last && h != H[i]) valid = false;
        }
        if(h > last){
            H[i] = h;
        }
        last = h;
    }

    if(!valid){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    REP(i,N){
        if(H[i] == 0){
            ans *= min(A[i], T[i]);
            ans %= MOD;
        }
    }

    cout << ans << endl;
    return 0;
}
