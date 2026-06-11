#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

const int MOD = 1e9 + 7;

int main(){
    int N;
    string S1, S2, arr;
    cin >> N >> S1 >> S2;
    rep(i, N) {
        if (S1[i] == S2[i]) arr += 'X';
        else {
            arr += 'Y';
            i++;
        }
    }
    ll ans;
    rep(i, arr.size()) {
        if (i == 0) {
            if (arr[0] == 'X') ans = 3;
            else ans = 6;
            continue;
        }
        if (arr[i-1] == 'X' && arr[i] == 'X') {
            ans *= 2;
            ans %= MOD;
        } else if (arr[i-1] == 'X' && arr[i] == 'Y') {
            ans *= 2;
            ans %= MOD;
        } else if (arr[i-1] == 'Y' && arr[i] == 'Y') {
            ans *= 3;
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}