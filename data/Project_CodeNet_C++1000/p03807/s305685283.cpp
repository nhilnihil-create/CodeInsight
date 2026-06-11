#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;
using Graph = vector<vector<int>>;

int main() {
    int n,temp,odd=0;
    cin>>n;
    rep(i,n) {
        cin>>temp;
        if (temp%2==1) odd++;
    }
    if (odd%2==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
