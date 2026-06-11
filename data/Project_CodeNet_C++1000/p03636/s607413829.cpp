#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    string s;
    cin>>s;
    int k=s.size()-2;
    string ans=s[0]+to_string(k)+s[s.size()-1];
    cout<<ans<<endl;
}
