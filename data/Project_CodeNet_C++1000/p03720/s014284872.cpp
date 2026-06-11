#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cnt[a]++;
        cnt[b]++;
    }
    rep(i,n){
        cout<<cnt[i]<<endl;
    }
}