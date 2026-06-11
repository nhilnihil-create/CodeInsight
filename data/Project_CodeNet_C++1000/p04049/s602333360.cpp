#include<bits/stdc++.h>
using namespace std;

int n,k,M,x,y;
vector<int> v[2000];

int dfs(int now,int from,int step)
{
    int ret=1;
    if(step<(int)(k/2)) for(int i=0;i<v[now].size();++i) if(v[now][i]!=from) ret+=dfs(v[now][i],now,step+1);
    return ret;
}

void maxExistNodes()
{
    if(k%2==0) for(int i=0;i<n;++i) M=max(M,dfs(i,-1,0));
    else       for(int i=0;i<n;++i) for(int j=0;j<v[i].size();++j) if(i<v[i][j]) M=max(M,dfs(i,v[i][j],0)+dfs(v[i][j],i,0));
}

void prepare()
{
    scanf("%i%i",&n,&k);
    for(int i=0;i<n-1;++i) {scanf("%i%i",&x,&y); --x; --y; v[x].push_back(y); v[y].push_back(x);}
}

int main()
{
    prepare();
    maxExistNodes();
    printf("%i\n",n-M);
    return 0;
}