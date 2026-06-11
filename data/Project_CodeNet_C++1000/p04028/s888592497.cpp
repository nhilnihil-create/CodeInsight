#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define Max(_A,_B) (_A>_B?_A:_B)

int n,f[5005][5005],len;
int clz=1E9+7;
char ch[5005];
long long pw(long long a,int b){
    long long nw=1;
    while(b){
        if(b&1){
            nw=nw*a%clz;
        }
        a=a*a%clz;
        b>>=1;
    }
    return nw;
}
void init(){
//    freopen("keyboard.in","r",stdin);
//    freopen("keyboard.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",ch);
    len=int(strlen(ch));
    f[0][0]=1;
    for(int i=0;i<=n;++i){
        for(int j=0;j<=i;++j){
            f[i+1][j+1]=int(1LL*f[i][j]*2%clz+f[i+1][j+1]%clz)%clz;
            f[i+1][Max(j-1,0)]=int(1LL*(f[i][j]+f[i+1][Max(j-1,0)])%clz);
        }
    }
    int anss=(int(pw(pw(2,len),clz-2)*f[n][len]%clz));
    printf("%d",anss);
}
//int(pw(pw(2,len),clz-2))*
int main(){
    init();
    return 0;
}