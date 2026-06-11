#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n,m,a,b;
    cin>>n>>m;
    bool ans[n],maki=0;
    memset(ans,0,sizeof(ans));
    for(int i=0;i<m;i++){
        cin>>a>>b;
        ans[a-1]^=1;
        ans[b-1]^=1;
    }
    for(int i=0;i<n;i++){
        maki|=ans[i];
    }
    cout << ((maki)?"NO":"YES")<<endl;
    return 0;
}