#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int n;
    cin >> n;
    ll a[n], b[n];
    ll amx = 0;
    ll cnt;
    rep(i, n){
        cin >> a[i] >> b[i];
        amx = max(amx, a[i]);
    }
    rep(i, n){
        if (amx == a[i]) cnt = i;
    }
    cout << b[cnt] + amx << endl;
    return 0;
}