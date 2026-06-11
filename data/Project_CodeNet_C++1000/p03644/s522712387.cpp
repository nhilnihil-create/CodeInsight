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
    int cnt = 0;
    while(n){
        n /= 2;
        cnt++;
    }
    cnt -= 1;
    int ans = 1;
    rep(i,cnt) ans *= 2;
    cout << ans << endl;
}