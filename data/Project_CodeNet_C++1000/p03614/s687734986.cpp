#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
static const ll maxLL = (ll)1 << 62;
const int mod=1000000007;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};


#define int ll




int n,m;
int p[100001];

signed main(){
    cin>>n;
    rep(i,0,n){
        cin>>p[i];
        p[i]--;
    }
    int cnt=0,i=0;
    for(i=0;i<n;++i){
        if(p[i]==i)cnt++,++i;
    }
    cout<<cnt<<endl;
    return 0;
}