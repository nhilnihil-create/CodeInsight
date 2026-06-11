#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n){
        cin >> a.at(i);
    }

    map<int, int> mp;
    rep(i, n){
        mp[a.at(i)]++;
    }

    int ans = 0;
    for(int i=1; i<=1e5+1; i++){
        int tmp = i-1;
        ans = max(ans, mp[tmp]+mp[tmp-1]+mp[tmp+1]);
    }

    cout << ans << endl;
    return 0;
}
