#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long lol;
template<typename T>
inline void gg(T &res){
    res=0;T fh=1;char ch=getchar();
    while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
    if(ch=='-')fh=-1,ch=getchar();
    while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
    res*=fh;
}
inline int gi(){int x;gg(x);return x;}
inline lol gl(){lol x;gg(x);return x;}
const int MAXN=100010;
const int INF=1e9;
int a[MAXN];
int main(){
    int n=gi();
    for(int i=1;i<=n;i++)a[i]=gi();
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        if(i+1>a[i+1]){
            bool res=1;
            for(int j=i+1;a[j]==i;j++)res^=1;
            res&=(a[i]-i+1)&1;
            printf(res?"Second":"First");
            break;
        }
    return 0; 
}