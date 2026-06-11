#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#define EPS 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
const int MOD = 1E9+7;
const int N = 1000000+5;
const int dx[] = {0,0,-1,1,-1,-1,1,1};
const int dy[] = {-1,1,0,0,-1,1,-1,1};
using namespace std;
int fatherRoad[N],fatherRail[N];
int Find(int father[],int x){
    if(x!=father[x])
        return father[x]=Find(father,father[x]);
    return x;
}
void Union(int father[],int x,int y){
    x=Find(father,x);
    y=Find(father,y);
    if(x!=y)
        father[y]=x;
}
int main() {
    int n,k,l;
    scanf("%d%d%d",&n,&k,&l);
    for(int i=1;i<=n;i++){
        fatherRoad[i]=i;
        fatherRail[i]=i;
    }
    for(int i=1;i<=k;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        Union(fatherRoad,x,y);
    }
    for(int i=1;i<=l;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        Union(fatherRail,x,y);
    }

    for(int i=1;i<=n;i++){
        Find(fatherRoad,i);
        Find(fatherRail,i);
    }
    map<pair<int,int>,int> mp;
    for(int i=1;i<=n;i++)
        mp[make_pair(fatherRoad[i],fatherRail[i])]++;
    for(int i=1;i<=n;i++)
        printf("%d\n",mp[make_pair(fatherRoad[i],fatherRail[i])]);
    return 0;
}
