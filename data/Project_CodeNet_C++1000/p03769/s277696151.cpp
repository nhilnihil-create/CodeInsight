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
LL C[55][55];
void build(){
    for(int i = 0;i<55;i++){
        C[i][i]=C[i][0]=1;
        for(int j=1;j<i;j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
}
vector<int> tmp;
int cnt=0;
void dfs(int i,vector<int> &q){
    if(i==q.size()){
        if(tmp.empty()||(tmp.size()&1))return ;
        int ok=1;
        for(int i = 0,j=tmp.size()/2;j<tmp.size();i++,j++){
            if(tmp[i]!=tmp[j])ok=0;
        }
        cnt+=ok;
        return ;
    }
    dfs(i+1,q);
    tmp.pb(q[i]);
    dfs(i+1,q);
    tmp.pop_back();
}
int main(){ 
    build();
    LL n;
    scanf("%lld",&n);
    vector<int> v;
    int tmp=1;
    LL val[55];
    for(int i = 1;i<55;i++){
        val[i]=(1ll<<i)-1;
    }
    for(int i = 54;i>0;i--){
      //  printf("%d %lld %lld\n",i,val[i],n);
        while(n>=val[i]){
            n-=val[i];
            //for(int _=0;_<2;_++)
            int ok=1;
            queue<int> q;
            for(int j=i/2;j<i;j++){
                int a=j,b=i+1-j;
                LL sum=0;
                for(int k=0;k<=min(a,b);k++){
                    sum+=C[a][k]*C[b][k];
                    if(sum>n)
                    break;
                }
              //  printf("?%d %d %lld\n",a,b,sum);
                while(sum<=n){
                    n-=sum;
                    q.push(a);
                }
            }
           // if(ok)
            int now=tmp+1;
            for(int j=0;j<=i;j++){
                while(!q.empty()&&q.front()==j){
                    q.pop();
                    v.pb(now++);
                }
                v.pb(tmp);
                
            }
            for(int j=now-1;j>tmp;j--){
                v.pb(j);
            }
            tmp=now;
           // printf("%d\n",tmp);
        }
    }
    printf("%d\n",v.size());
    for(auto it:v)
    printf("%d ",it);
    printf("\n");
  //  dfs(0,v);
  //  printf("%d\n",cnt);
}
/*
2 2 1
3 2 3
4 2 4 4 7

*/