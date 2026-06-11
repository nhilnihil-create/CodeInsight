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
    int n,x;
    scanf("%d %d",&n,&x);
    n=2*n-1;
    if(x==1||x==n){
        printf("No\n");
    }
    else{
        printf("Yes\n");
        if(n==3){
            printf("1\n2\n3\n");
            return 0;
        }
        int ans[200005];
        fill(ans,ans+n,0);
        set<int> s;
        for(int i = 1;i<=n;i++)
        s.insert(i);
        ans[n/2]=x;
        s.erase(x);
        if(x==n-1){
            ans[n/2+1]=n;
            s.erase(n);
            ans[n/2+2]=n-2;
            s.erase(n-2);
            ans[n/2-1]=n-3;
            s.erase(n-3);
        }
        else{
            ans[n/2+1]=x-1;
            s.erase(x-1);
            ans[n/2+2]=x+1;
            s.erase(x+1);
            ans[n/2-1]=x+2;
            s.erase(x+2);
        }
        for(int i = 0;i<n;i++){
            if(ans[i]==0){
                printf("%d\n",*s.begin());
                s.erase(s.begin());
            }
            else{
                printf("%d\n",ans[i]);
            }
        }
        //printf("\n");
    }
}
/*

b[i]*K!/(i)!*(K-i)!
*/