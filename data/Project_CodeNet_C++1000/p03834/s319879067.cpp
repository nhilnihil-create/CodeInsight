#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    string s;
    cin>>s;
    string ans=s.substr(0,5)+" "+s.substr(6,7)+" "+s.substr(14,5);
    cout<<ans<<endl;
}
