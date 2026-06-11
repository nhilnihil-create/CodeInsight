#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int h,w;
    cin>>h>>w;
    vector<string> c(h),ans;
    rep(i,h) {
        cin>>c[i];
        rep(j,2) ans.push_back(c[i]);
    }
    rep(i,2*h) cout<<ans[i]<<endl;
}
