#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) (v).begin(),(v).end()
#define out(a) cout << (a) << endl
using namespace std;
using ll = long long;
int main(){
    int n, t;
    cin >> n >> t;
    vector<int> vec(n);
    rep(i, n) cin >> vec[i];
    int ans= n * t;
    rep(i, n-1){
        if(t > vec[i+1] - vec[i]){
            ans -= (vec[i] + t - vec[i+1]);
        }
    }
    out(ans);
}