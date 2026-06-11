#include<bits/stdc++.h>
#pragma optimizer(O2)
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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
//#define MXN 300000
#define N 100005

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> odd,even;
    for(int i = 0;i<m;i++){
        int x;
        scanf("%d",&x);
        if(x&1)odd.pb(x);
        else even.pb(x);
    }
    if(odd.size()>2){
        printf("Impossible\n");
    }
    else{
        if(n&1){
            for(auto it:odd)printf("%d",it);
            for(auto it:even)printf(" %d",it);
            if(m!=1||n==1){
                odd[0]--;
                if(odd[0]==0)m--;
                printf("\n%d\n",m+1);
                for(auto it:odd)if(it)printf("%d",it);
                for(auto it:even)printf(" %d",it);
                printf(" 1\n");
            }
            else{
                printf("\n2\n");
                printf("1 %d\n",n-1);
            }
        }
        else{
            if(odd.size()){
                printf("%d",odd[0]);
                for(auto it:even)
                printf(" %d",it);
                printf(" %d\n",odd[1]);
                odd[0]--;
                odd[1]++;
                if(odd[0]==0){
                    printf("%d\n",m-1);
                    for(auto it:even)
                    printf("%d ",it);
                    printf("%d\n",odd[1]);
                }
                else{
                    printf("%d\n",m);
                     printf("%d",odd[0]);
                    for(auto it:even)
                    printf(" %d",it);
                    printf(" %d\n",odd[1]);
                }
            }
            else{
                for(auto it:even)printf("%d ",it);
                printf("\n");
                printf("%d\n",m+1);
                printf("1");
                even.back()--;
                for(auto it:even)printf(" %d",it);
                printf("\n");
            }
        }
    }
}