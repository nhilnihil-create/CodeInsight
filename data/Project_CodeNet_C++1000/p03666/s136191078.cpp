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
#define pow POW
int main(){
    int n,a,b,c,d;
    scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
    LL now=a;
    for(int i = 2;i<=n;i++){
        if(now+c>b){
            now-=d;
        }
        else{
            now+=c;
        }
    }
    if(b-now<=(n-1)*(d-c)){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
/*
7 7
1 1 4 7
1 1 2 5
1 2 6 7
1 1 5 8
1 1 3 6
1 3 7 5
0 1 6 7
d-1 2-d 3-d=d
d-1 2-d 3-d 4-d
12 02 0 1
a1 a2 a3 a4
a1-a2-a3-a4
a1-a2-a3+a4
a1-a2+a3-a4
a1-a2+a3+a4
a1-a2-a3+a4
a1-a2+a3-a4
*/
//a+a+1=10a+1
//3a+2=10a+2