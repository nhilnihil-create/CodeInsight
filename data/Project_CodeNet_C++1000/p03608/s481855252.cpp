#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
ll n,m,R;
ll r[10];
ll a[20000],b[20000],c[20000];
ll d[205][205];
ll ans=1000000000000000000;
ll p[8];
int main(void){
    cin>>n>>m>>R;
    for(int i=0;i<R;i++){
        cin>>r[i];
    }
    sort(r,r+R);
    for(int i=0;i<205;i++){
        for(int j=0;j<205;j++){
            d[i][j]=1000000000000000000;
            if(i==j){
                d[i][j]=0;
            }
        }
    }
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i]>>c[i];
        d[a[i]-1][b[i]-1]=c[i];
        d[b[i]-1][a[i]-1]=c[i];
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    for(int i=0;i<R;i++){
        p[i]=i;
    }
    do{
        ll C=0;
        for(int i=1;i<R;i++){
            C+=d[r[p[i-1]]-1][r[p[i]]-1];
        }
        /*for(int i=0;i<R;i++){
            cout<<r[p[i]]<<" ";
        }
        cout<<C<<endl;*/
        ans=min(ans,C);
    } while(next_permutation(p,p+R));
    cout<<ans<<endl;
    
}
