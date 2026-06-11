#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define MXN 200005
int main(){ 
    int n,l,t;
    scanf("%d %d %d",&n,&l,&t);
    pii p[100005];
    for(int i = 1;i<=n;i++){
        scanf("%d %d",&p[i].x,&p[i].y);
    }
    vector<pii> v;
    for(int i = 1;i<=n;i++){
        if(p[i].y==1){
            v.pb(mp((p[i].x+t)%l,i));
        }
        else{
            v.pb(mp(((p[i].x-t)%l+l)%l,i));
        }
    }
    sort(v.begin(),v.end());
    int cnt=0;
    for(int i = 2;i<=n;i++){
        if(p[i].y!=p[1].y){
            if(p[1].y==1){
                int dis=p[i].x-p[1].x;
                cnt+=2*t/l;
                cnt+=(2*t%l>dis);
            }
            else{
                int dis=l-(p[i].x-p[1].x);
                cnt-=2*t/l;
                cnt-=(2*t%l>=dis);
            }
        }
    }
    //printf("%d\n",cnt);
    int num=(cnt%n+n)%n+1;
    int ans[100005];
    int i;
    for(i=0;v[i].y!=1;i++){
        v.pb(v[i]);
    }
    for(;i!=v.size();i++){
        ans[num]=v[i].x;
        num=num%n+1;
    }
    for(int i = 1;i<=n;i++)
        printf("%d\n",ans[i]);
}
/*
1 2 2 3 3 3 4
2 2 1
3 2 3
4 2 4 4 7
 
*/