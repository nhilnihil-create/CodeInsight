#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;
    
    map<int,int> mp;
    rep(i, N) {
        int a;
        cin >> a;
        ++mp[a];
    }

    int ans = 0;
    for(int i=2;i<=1e5+1;++i){
        int tmp =0;
        tmp += mp[i] + mp[i-1] + mp[i-2];
        ans = max(ans,tmp);
    }
    cout << ans << endl;
}
