#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline int read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y){
    x^=y^=x^=y;
}
inline int _abs(const res &x){
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y){
    return x>y?x:y;
}
inline int _min(const res &x,const res &y){
    return x<y?x:y;
}
const int N=1e5+10;
namespace MAIN{
    inline bool cmp(const res &x,const res &y){
        return x>y;
    }
    int n,a[N];
    inline void MAIN(){
        n=read();
        for(res i=1;i<=n;i++)a[i]=read();
        sort(a+1,a+n+1,cmp);
        for(res i=1;i<=n;i++)
            if(i+1>a[i+1]){
                res j=i+1,ans=0;
                while(a[j]==i)ans^=1,j++;
                if((ans||((a[i]-i)&1)))puts("First");
                else puts("Second");
                return;
            }
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}