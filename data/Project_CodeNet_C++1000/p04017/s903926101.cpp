#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=1e9;
const int mod=1e9+7;
const int maxn=5e5+10;
int n,x[maxn];
int l,q,a,b;
int nex[maxn][20];
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    cin>>l>>q;
    for(int i=1;i<=n;i++) nex[i][0]=upper_bound(x+i,x+n+1,x[i]+l)-x-1;
    for(int i=0;i<19;i++){
        for(int j=1;j<=n;j++){
            nex[j][i+1]=nex[nex[j][i]][i];
        }
    }
    while(q--){
        cin>>a>>b;
        int ans=0;
        if(a>b) swap(a,b);
        for(int i=19;i>=0;i--){
            if(nex[a][i]<b){
                a=nex[a][i];
                ans+=(1<<i);
            }
        }
        cout<<ans+1<<endl;
    }
    return 0;
}
