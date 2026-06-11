#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> ans(n,0);
    rep(i,m){
        int a, b; cin >> a >> b;
        ans[a-1]++;
        ans[b-1]++;
    }
    bool check = true;
    rep(i,n) if(ans[i] % 2 == 1) check = false;
    cout << (check ? "YES" : "NO") << endl;
}