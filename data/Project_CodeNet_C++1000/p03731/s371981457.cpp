#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;
const int INF = 999999999;

int main(){
    ll N, T;
    cin >> N >> T;
    vector<ll> t(N);
    rep(i, N){
        cin >> t[i];
    }
    int ans = 0;
    rep(i, N){
        if(i != N-1){
            if(t[i+1] - t[i] > T){
                ans += T;
            }else{
                ans += t[i+1] - t[i];
            }
        }else{
            ans += T;
        }
    }
    cout << ans << endl;
return 0;}
/**
 * g++ code.cpp
 * ./a.out
 * shift + ctrl + i
**/ 