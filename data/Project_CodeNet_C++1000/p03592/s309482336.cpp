#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    bool flag = false;
    rep(a, n + 1){
        rep(b, m + 1){
            if ((a * (m - b) + b * (n - a)) == k) flag = true;
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}