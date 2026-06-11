#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    string a,b,ans;
    cin>>a>>b;
    if (a.size()!=b.size()) {
        if (a.size()>b.size()) ans="GREATER";
        else if(a.size()<b.size()) ans="LESS";
        else ans="EQUAL";
    } else {
        if (a>b) ans="GREATER";
        else if(a<b) ans="LESS";
        else ans="EQUAL";
    }
    cout<<ans<<endl;
}
