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
LL bucket[10];
pair<int,int> node[N];
map<pair<int,int>,int> mp;
int main(){
    LL h,w,n;
    scanf("%lld%lld%lld",&h,&w,&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&node[i].first,&node[i].second);
        mp[node[i]]=1;//涂黑的格子贡献度为1
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<8;j++){
            int nx=node[i].first+dx[j];
            int ny=node[i].second+dy[j];
            if(nx>=1&&nx<=h&&ny>=1&ny<=w){
                pair<int,int> temp(nx,ny);
                mp[temp]++;
            }
        }
    }

    LL sum=0;
    LL tot=(h-2)*(w-2);
    map<pair<int,int>,int>::iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        int x=it->first.first;
        int y=it->first.second;
        int val=it->second;
        if(x>=2&&x<=h-1&&y>=2&y<=w-1){
            bucket[val]++;
            sum++;
        }
    }
    bucket[0]=tot-sum;

    for(int i=0;i<=9;i++)
        printf("%lld\n",bucket[i]);

    return 0;
}