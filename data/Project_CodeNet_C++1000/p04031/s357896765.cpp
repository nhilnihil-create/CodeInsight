#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = 1001001001;
    for(int i = -100; i <= 100; i++){
        int tmp = 0;
        rep(j,n) tmp += (a[j] - i) * (a[j] - i);
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}