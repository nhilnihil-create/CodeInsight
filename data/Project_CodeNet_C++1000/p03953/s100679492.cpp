#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m;
long long k;
long long x[N];
int v[N],p[N],vis[N],fin[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
    for(int i=1;i<n;i++) v[i]=x[i+1]-x[i],p[i]=i;
    scanf("%d%lld",&m,&k);
    for(int i=1,t;i<=m;i++){
        scanf("%d",&t);
        swap(p[t-1],p[t]);
    }
    for(int i=1;i<n;i++)
        if(vis[i]==0){
            vector<int> vec;vec.push_back(i);
            for(int j=p[i];j!=i;j=p[j]) vec.push_back(j);
            int num=k%vec.size();
            for(int j=0;j<vec.size();j++){
                fin[vec[j]]=vec[(j+num)%vec.size()];
                vis[vec[j]]=1;
            }
        }
    for(int i=1;i<n;i++) fin[i]=v[fin[i]];
    for(int i=2;i<=n;i++) x[i]=x[i-1]+fin[i-1];
    for(int i=1;i<=n;i++) printf("%lld\n",x[i]);
    return 0;
}