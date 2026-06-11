#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;

ll mypow(ll p, ll n){
    ll res = 1;
    while (n>0){
        if (n%2==0){
            p *= p;
            n /= 2;
        } else {
            res *= p;
            n--;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, P;
    cin >> N >> P;
    vector<ll> A(N);
    bool isodd = false;
    for (int i=0;i<N;i++){
        cin >> A[i];
        if (A[i]%2==1) isodd = true;
    }
    ll odd, even;
    if (isodd){
        odd = even = mypow(2, N-1);
    } else {
        odd = 0;
        even = mypow(2, N);
    }

    if (P==0)  cout << even << "\n";
    else cout << odd << "\n";
}