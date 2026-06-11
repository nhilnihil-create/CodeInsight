#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;

ll mod = 1000000007;
ll ans = 1<<29;

int main() {
    ll n,k;
    cin>> n >> k;
    vector<pair<ll,ll>> P (n);
    rep(i,n){
        cin >> P[i].first>>P[i].second;
    }
    sort(P.begin(),P.end());
    ll sum = 0;
    ll index;
    rep(i,n){
        sum +=P[i].second;
        if(sum>=k) {
            index = i;
            break;
        } 
    }
    cout << P[index].first << endl;
}