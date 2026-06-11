#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const ll INF = 1001001001001001001;
const int MAX = 5e5 + 10;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll sum = 0, ans = INF, tmp = 0;
    rep(i,n){
        sum += a[i];
        if(i % 2 == 0 && sum <= 0){
            tmp += 1 - sum;
            sum = 1;
        }
        if(i % 2 == 1 && sum >= 0){
            tmp += sum + 1;
            sum = -1;
        }
    }
    ans = min(ans, tmp);
    tmp = 0;
    sum = 0;
    rep(i,n){
        sum += a[i];
        if(i % 2 == 0 && sum >= 0){
            tmp += sum + 1;
            sum = -1;
        }
        if(i % 2 == 1 && sum <= 0){
            tmp += 1 - sum;
            sum = 1;
        }
    }
    ans = min(ans, tmp);
    cout << ans << endl;
}