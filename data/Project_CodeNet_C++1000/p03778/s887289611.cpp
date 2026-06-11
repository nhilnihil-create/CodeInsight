#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int w,a,b,ans;
    cin>>w>>a>>b;
    if (b+w<a) ans=a-b-w;
    else if (a+w<b) ans=b-a-w;
    else ans=0;
    cout<<ans<<endl;
}
