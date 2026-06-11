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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005

int main(){
    int n;
    scanf("%d",&n);
    int a[100005];
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    if(a[n-1]-a[0]>1){
        printf("No\n");
    }
    else{
        int cnt=0;
        int tot=0;
        for(int i = 0;i<n;i++){
            if(a[i]==a[n-1]-1)cnt++;
            else tot++;
        }
        a[n-1]-=cnt;
        if(cnt==0&&a[n-1]==n-1){
            printf("Yes\n");
        }
        else if(a[n-1]*2>tot||a[n-1]<=0){
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }
    }
}
/*

23847657 
23458792534

102334155
111111111 
111111111
*/