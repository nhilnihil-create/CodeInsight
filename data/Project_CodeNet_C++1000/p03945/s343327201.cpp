#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    string s;
    cin>>s;
    int ans=1;
    rep(i,s.size()-1) if (s[i]!=s[i+1]) ans++;
    cout<<ans-1<<endl;
}   
