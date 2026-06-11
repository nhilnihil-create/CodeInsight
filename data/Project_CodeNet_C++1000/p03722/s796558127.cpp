#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=1e18;

int main(){
    int n,m;
    cin>>n>>m;
    int a[m],b[m];
    ll c[m];
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--,b[i]--;
        c[i]*=-1;
    }
    ll d[n];
    fill(d,d+n,LINF);
    d[0]=0;
    bool flag=false,reach[n]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(d[a[j]]!=LINF&&d[b[j]]>d[a[j]]+c[j]){
                d[b[j]]=d[a[j]]+c[j];
                if(i==n-1){
                    flag=true;
                    reach[a[j]]=reach[b[j]]=true;
                }
            }
        }
    }
    if(flag){
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                reach[b[j]]|=reach[a[j]];
            }
        }
    }
    if(reach[n-1])cout<<"inf"<<endl;
    else cout<<-d[n-1]<<endl;
}
