#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }


int main(){
    ll N, ans = 1;
    cin >> N;
    vector<ll> A(N, 0);
    for(int i = 0; i < N; i++) cin >> A[i];
    ll w = 0;
    for(int i = 0; i < N - 1; i++){
        if(w == 1 && A[i] < A[i + 1] || w == -1 && A[i] > A[i + 1]){
            ans++;
            w = 0;
        }
        else if(A[i] > A[i + 1] ) w = 1;
        else if(A[i] < A[i + 1] ) w = -1;
    }

    cout << ans << endl;
    return 0;

}
