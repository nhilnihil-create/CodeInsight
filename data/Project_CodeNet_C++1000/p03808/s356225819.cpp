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
    LL n;
    scanf("%lld",&n);
    LL tot=n*(n+1)/2;
    LL sum=0;
    LL a[100005];
    for(int i = 0;i<n;i++)
        scanf("%lld",&a[i]),sum+=a[i];
    if(sum%tot!=0){
        printf("NO\n");
        return 0;
    }
    LL ti=sum/tot;
    LL cnt=0;
    for(int i = 0;i<n;i++){
        LL x=a[(i+1)%n]-a[i];
        LL sub=ti-x;
        if(sub%n!=0||sub<0){
            printf("NO\n");
            return 0;
        }

        cnt+=sub/n;
    }
    if(cnt==ti){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}