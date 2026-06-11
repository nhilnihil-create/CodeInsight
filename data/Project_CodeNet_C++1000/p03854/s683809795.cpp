#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    string s;
    cin>>s;
    string l[4]={"dream","dreamer","erase","eraser"};
    rep(i,4) reverse(l[i].begin(),l[i].end());
    reverse(s.begin(),s.end());
    bool f1=true;
    rep(i,s.size()) {
        bool f2=false;
        rep(j,4) {
            string t=l[j];
            if (s.substr(i,t.size())==t) {
                f2=true;
                i+=t.size()-1;
            }
        }
        if (!f2) {
            f1=false;
            break;
        }
    }
    if (f1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
