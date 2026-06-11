#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,L,T;
int pos[N],v[N];
int main(){
    scanf("%d%d%d",&n,&L,&T);
    for(int i=1;i<=n;i++) scanf("%d%d",&pos[i],&v[i]),v[i]=v[i]==1? 1:-1;
    vector<int> fin;
    for(int i=1;i<=n;i++)
        fin.push_back(((pos[i]+v[i]*T)%L+L)%L);
    int pos1=fin[0];
    sort(fin.begin(),fin.end());
    long long tot=0;
    for(int i=1;i<=n;i++)
        if(v[i]!=v[1])
            tot+=(2*1LL*T+(v[1]==1? (L-pos[i]+pos[1]):(pos[i]-pos[1])) )/L;
    tot=((v[1]*tot)%n+n)%n;
    int id1=0;
    for(int i=0;i<n;i++)
        if(fin[i]==pos1){
            id1=i;
            if(v[1]==-1) break;
        }
    id1=((id1-tot)%n+n)%n;
    for(int i=id1;i<n;i++)
        printf("%d\n",fin[i]);
    for(int i=0;i<id1;i++)
        printf("%d\n",fin[i]);
    return 0;
}