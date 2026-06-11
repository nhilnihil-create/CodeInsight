#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int main()
{
LL n,m,i;
vector<pair<LL,LL>>v1,v2;
scanf("%lld %lld",&n,&m);
for(i=0;i<n;++i){
    LL x,y;
    scanf("%lld %lld",&x,&y);
    v1.emplace_back(x,y);
}
for(i=0;i<m;++i){
    LL x,y;
    scanf("%lld %lld",&x,&y);
    v2.emplace_back(x,y);
}
for(i=0;i<n;++i){
    LL x,y,mini=OO;
    x=v1[i].first,y=v1[i].second;
    for(int j=0;j<m;++j){
        LL x1,y1,sum;
        x1=v2[j].first,y1=v2[j].second;
        sum=abs(x-x1)+abs(y-y1);
        mini=min(mini,sum);
    }
    for(int j=0;j<m;++j){
        LL x1,y1,sum;
        x1=v2[j].first,y1=v2[j].second;
        sum=abs(x-x1)+abs(y-y1);
        if(mini==sum){
            printf("%d\n",j+1);
            break;
        }
    }
}




    return 0;
}
