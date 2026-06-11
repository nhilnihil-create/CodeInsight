#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) (v).begin(),(v).end()
#define out(a) cout << (a) << endl
using namespace std;
using ll = long long;

int main(){
    vector<ll> A(100010, 0);
    ll n;
    cin >> n;
    rep(i, n){
        ll num;
        cin >> num;
        num++;
        A[num-1]++;
        A[num]++;
        A[num+1]++;
    }
    ll c=0;
    rep(i, 100010) c = max(c, A[i]);
    out(c);
}