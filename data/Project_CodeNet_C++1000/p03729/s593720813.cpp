#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    string a,b,c;
    cin>>a>>b>>c;
    if (a[a.size()-1]==b[0]&&b[b.size()-1]==c[0]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
