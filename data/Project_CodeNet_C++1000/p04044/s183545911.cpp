#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, l; cin >> n >> l;
    vector<string> vec(n);
    rep(i,n) cin >> vec[i];
    sort(ALL(vec));
    string ans = "";
    rep(i,n) ans += vec[i];
    cout << ans << endl;
}