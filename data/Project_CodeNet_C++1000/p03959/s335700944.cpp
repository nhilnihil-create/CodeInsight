#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

void solve();

int main(void){
    int N; cin >> N;
    int A[N], T[N];
    rep(i, N) cin >> T[i];
    rep(i, N) cin >> A[i];
    bool contradict = false;
    int choice1[N], choice2[N];
    int highest = 0;
    if(T[0] > A[0] || T[N-1] < A[N-1]){
        contradict = true;
    }
    choice1[0] = 1;
    choice2[N-1] = 1;
    for(int i = 1; i < N; i++){
        if(T[i] != T[i-1]){
            highest = i;
            choice1[i] = 1;
            if(T[i] > A[i]) contradict = true;
        }
        else{
            choice1[i] = T[highest];
        }
    }
    highest = N-1;
    for(int i = N-2; i >= 0; i--){
        if(A[i] != A[i+1]){
            highest = i;
            choice2[i] = 1;
            if(A[i] > T[i]) contradict = true;
        }
        else{
            choice2[i] = A[highest];
        }
    }
    if(contradict) cout << 0 << endl;
    else{
        ll ans = 1;
        rep(i, N) ans = ans*min(choice1[i], choice2[i]) % mod;
        cout << ans << endl;
    }
    return 0;
}

void solve(){}