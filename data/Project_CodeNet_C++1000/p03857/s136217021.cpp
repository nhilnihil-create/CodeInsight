#include<bits/stdc++.h>
using namespace std;
int par1[200001],par2[200001];
vector<pair<int,int>> idx;
map<pair<int,int>,int> cnt;
int rep1(int n)
{
    if(par1[n]==n)
        return n;
    return par1[n]=rep1(par1[n]);
}
int rep2(int n)
{
    if(par2[n]==n)
        return n;
    return par2[n]=rep2(par2[n]);
}
int main()
{
    int i,j;
    int n,k,l;
    int a,b,res=0;
    scanf("%d %d %d",&n,&k,&l);
    for(i=1;i<=n;i++){
        par1[i]=i;
        par2[i]=i;
    }
    for(i=0;i<k;i++){
        scanf("%d %d",&a,&b);

        int r1=rep1(a);
        int r2=rep1(b);
        par1[r1]=r2;
    }
    for(i=0;i<l;i++){
        scanf("%d %d",&a,&b);
        int r1=rep2(a);
        int r2=rep2(b);
        par2[r2]=r1;
    }
    for(i=1;i<=n;i++){

        idx.push_back(make_pair(rep1(i),rep2(i)));
    }

    for(i=0;i<idx.size();i++){
            //assert(idx[i].first == idx[i].second);
        cnt[idx[i]]++;
       // printf("%d %d\n",idx[i].first,idx[i].second);
    }
    for(i=0;i<idx.size();i++)
        printf("%d ",cnt[idx[i]]);
}