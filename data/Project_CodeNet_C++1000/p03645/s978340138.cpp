#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n,m,temp1,temp2;
    cin>>n>>m;
    vector<bool> f1(n,false),f2(n,false);
    bool flag=false;
    rep(i,m) {
        cin>>temp1>>temp2;
        if (temp1==1) f1[temp2-1]=true;
        if (temp2==n) f2[temp1-1]=true;
    }
    rep(i,n) {
        if (f1[i]&&f2[i]) flag=true;
    }
    if (flag) cout<<"POSSIBLE"<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
}
