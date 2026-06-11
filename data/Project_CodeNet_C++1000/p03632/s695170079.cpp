#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int l=max(a,c),r=min(b,d);
    cout<<max(0,r-l)<<endl;
    return 0;
}