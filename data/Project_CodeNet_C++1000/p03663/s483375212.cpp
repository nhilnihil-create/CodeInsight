#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MAX=109999;
const ll INF=0x3f3f3f3f3f3f3f;
vector<int> conn[MAX];
queue<pii> bfs;
int ans[20],len,q;
int find_len(){
    int t=10,i;
    char tmp[10];
    for(i=1;i<=9;i++,t*=10){
        printf("? %d\n",t);
        fflush(stdout);
        scanf(" %s",tmp);
        if(tmp[0]=='N'){
            return i;
        }
    }
    t=2; q=1;
    for(i=0;i<=9;i++,t*=10){
        printf("? %d\n",t);
        fflush(stdout);
        scanf(" %s",tmp);
        if(tmp[0]=='Y'){
            return i;
        }
    }
    return -1;
}
int range(int x,int y,int r){
    int p=(x+y)/2;
    char tmp[10];
    if(y-x==1) return x;
    ans[r]=p;
    printf("? ");
    for(int i=0;i<len+1;i++) printf("%d",ans[i]);
    printf("\n");
    fflush(stdout);
    scanf(" %s",tmp);
    if(tmp[0]=='N') return range(p,y,r);
    return range(x,p,r);
}
int build(){
    int t=0;
    for(int i=0;i<len;i++) t*=10,t+=ans[i];
    return t+1;
}
int main()
{
    len=find_len();
    if(q==1){
        int t=1;
        for(int i=0;i<len;i++) t*=10;
        printf("! %d\n",t);
        fflush(stdout);
        return 0;
    }
    ans[0]=range(1,10,0);
    for(int i=1;i<len;i++) ans[i]=range(0,10,i);
    printf("! %d",build());
    printf("\n");
    fflush(stdout);
}
