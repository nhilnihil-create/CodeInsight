#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define xrep(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define vl vector<long long>
#define vs vector<string>

int main() {
    vl A(3);
    rep(i,3){
        cin >> A[i];
    }

    sort(A.begin(),A.end());

    if(A[0] == 5 && A[1] == 5 && A[2] == 7){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}