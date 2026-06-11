#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    rep(i, n) {
        int a; cin >> a;
        mp[a]++;
    }
    int cnt = 0;
    for(auto it=mp.begin();it!=mp.end();it++) {
        cnt += (it->second - 1);
    }
    cout << n - 2*((cnt+1)/2);
}
