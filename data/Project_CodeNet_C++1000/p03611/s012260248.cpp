#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> a(100005);
    rep(i,n){
        int x;
        cin >> x;
        a[x]++;
    }
    int ans = 0;
    rep(i,100000){
        int cnt = 0;
        rep(j,3) cnt += a[i+j];
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}