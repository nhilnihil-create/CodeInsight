#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    string o,e,ans="";
    cin>>o>>e;
    int n=o.size()+e.size();
    rep(i,n) {
        if (i%2==0) {
            ans.push_back(o[0]);
            o.erase(0,1);
        } else {
            ans.push_back(e[0]);
            e.erase(0,1);
        }
    }
    cout<<ans<<endl;
}
