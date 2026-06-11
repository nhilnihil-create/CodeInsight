#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int grid[105][105];

int main(){
    int n;cin >> n;
    vector<int> a(n);
    rep(i,n) cin>> a[i];
    ll ans = 0;
    rep(i,n-1){
        ans += a[i]/2;
        a[i] %= 2;
        if(a[i+1]>0&&a[i]==1){
            ans++;
            --a[i+1];
            --a[i];
        }
    }
    ans += a[n-1]/2;

    cout << ans << endl;
}