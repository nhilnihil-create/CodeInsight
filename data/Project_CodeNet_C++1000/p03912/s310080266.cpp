#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;scanf("%d%d",&n,&m);
    map<int,int> a;
    for(int i=0;i<n;i++){
        int x;scanf("%d",&x);
        a[x]++;
    }
    vector<int> modm(m),modmp(m);
    for(auto p:a){
        modm[p.first%m]+=p.second%2;
        modmp[p.first%m]+=p.second/2*2;
    }
    int ans=modm[0]/2;
    for(int i=0;i<(m-1)/2;i++){
        int p=min(modm[i+1],modm[m-1-i]);
        ans+=p;
        modm[i+1]-=p,modm[m-1-i]-=p;
    }
    if((m-1)%2)ans+=modm[m/2]/2,modm[m/2]%=2;
    for(int i=0;i<m-1;i++){
        if(modm[i+1]<=1)continue;
        int p=min(modm[i+1],modmp[m-1-i]);
        ans+=p;
        modm[i+1]-=p,modmp[m-1-i]-=p;
    }
    for(int i=0;i<m;i++)ans+=modmp[i]/2;
    printf("%d\n",ans);
    return 0;
}