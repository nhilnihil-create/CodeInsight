#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<string> board(2);
    rep(i, 2) {
        cin >> board[i];
    }

    vector<int> v;  // v[i] : 0のとき縦(解説のX)、1のとき横(解説のY)
    rep(j, n) {
        if(board[0][j] == board[1][j]) {
            v.push_back(0);    
        }
        else {
            v.push_back(1);
            j++;
        }
    }

    ll ans;
    if(v[0] == 0) {
        ans = 3LL;
    }
    else {
        ans = 6LL;   
    }

    rep(i, v.size()-1) {
        if(v[i] == 0 && v[i+1] == 0) {
            ans *= 2LL;
        }
        else if(v[i] == 1 && v[i+1] == 0) {
            ans *= 1LL;
        }
        else if(v[i] == 0 && v[i+1] == 1) {
            ans *= 2LL;
        }
        else if(v[i] == 1 && v[i+1] == 1) {
            ans *= 3LL;
        }
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}