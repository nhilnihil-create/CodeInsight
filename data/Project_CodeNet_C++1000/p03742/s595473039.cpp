#include<bits/stdc++.h>
using namespace std;

template <typename T>
inline T read(){
    T x=0,f=1;char c=getchar();
    while(!isdigit(c)){ if(c=='-') f=-f;c=getchar();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c-48);c=getchar();}
    return x*f;
}

#define lint long long int
#define ulint unsigned lint
#define readint read<int>()
#define readlint read<lint>()
const int inf=1e9+1e7;

lint n,m;

int main(void){

    // freopen("testdata.in","r",stdin);
    // freopen("testdata.out","w",stdout);

    scanf("%lld%lld",&n,&m);
    if(abs(n-m)<=1) puts("Brown");
    else puts("Alice");

    return 0;
}