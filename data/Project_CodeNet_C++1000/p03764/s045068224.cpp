/*g++ main.cpp -o main.out*/
/*./main.out*/
/*std::ios::sync_with_stdio(false);cin.tie(0);*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define Mod 1000000007
#define L_Mod 17100000013

const double eps = 1e-9;
const int INF = 0x3f3f3f3f;
const double PI = 3.1415926535;

#define ree(n,a) memset(n,a,sizeof(n));

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define red(i,l,u) for(int (i)=(int)(l);(i)>=(int)(u);--(i))

LL x[100005],y[100005];

int main()
{
    //std::ios::sync_with_stdio(false);
    int n,m;
    scanf("%d%d",&n,&m);
    rer(i,1,n)scanf("%lld",&x[i]);
    rer(i,1,m)scanf("%lld",&y[i]);
    LL a=0,b=0;
    rer(i,1,n)
    {
        a+=((2*i-1-n)*x[i])%Mod;
        a%=Mod;
    }
    rer(i,1,m)
    {
        b+=((2*i-1-m)*y[i])%Mod;
        b%=Mod;
    }
    printf("%lld\n",(a*b)%Mod);
    return 0;
}