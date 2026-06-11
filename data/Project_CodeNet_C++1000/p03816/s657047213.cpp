#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);

    map<int, int> mp;
    rep(i, n){
        mp[a.at(i)]++;
    }

    int ans = 0;
    int mnid = 100000;
    int mxid = -1;
    int cnt = 0;
    for(auto b: mp){
        ans++;
        if(b.second%2==0){
            cnt++;
            mnid = min(mnid, b.first);
            mxid = max(mxid, b.first);
        }
        else{
            b.second = 1;
        }
    }

    dump(mnid);
    dump(mxid);

    if(cnt%2==0){
        cout << ans << endl;
        return 0;
    }

    cout << ans - 1<< endl;

    
    return 0;
}