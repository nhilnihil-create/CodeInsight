#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,l[310000],r[310000],tree[110000];
vector<int> vec[110000];
void add(int x,int y){
    for (;x<=m;x+=x&-x) tree[x]+=y;
}
int getsum(int x){
    int sum=0;
    for (;x;x-=x&(-x)) sum+=tree[x];
    return sum;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%d%d",&l[i],&r[i]);
        vec[r[i]-l[i]+1].push_back(i);
    }
    for (int i=1;i<=m;i++){
        int ans=0;
        for (int j=0;j<(int)vec[i].size();j++)
            add(l[vec[i][j]],1),add(r[vec[i][j]]+1,-1);
        for (int j=i;j<=m;j+=i) ans+=getsum(j);
        n-=vec[i].size();
        printf("%d\n",ans+n);
    }
    return 0;
}
//