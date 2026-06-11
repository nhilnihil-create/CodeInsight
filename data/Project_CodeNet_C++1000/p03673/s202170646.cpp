#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n,temp,rev=0;
    cin>>n;
    deque<int> ans;
    rep(i,n) {
        cin>>temp;
        if (rev) ans.push_front(temp);
        else ans.push_back(temp);
        rev=1-rev;
    }
    if (rev) reverse(ans.begin(),ans.end());
    for (auto v : ans) cout<<v<<" ";
    cout<<endl;
}
