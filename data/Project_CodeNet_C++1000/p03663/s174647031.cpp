#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
char s[10];
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
void write(int x){print(x);puts("");}
void query(ll  x){printf("? %lld\n",x);fflush(stdout);scanf("%s",s);}
int main(){
    int x=1e9;query(x);
    if(s[0]=='Y'){
        for(int i=9;i;i--){
            query(x-1);
            if(s[0]=='N')break;
            x/=10;
        }printf("! %d\n",x);
        return 0;
    }//特判类似10000这种情况
    for(int i=9;i;i--){
        x/=10;query(x);
        if (s[0]=='Y')break;
    }int l=x+1,r=x*10-1,ans;
    while(l<=r){
        ll mid=(l+r)>>1;query(mid*10);
        if(s[0]=='Y')r=mid-1,ans=mid;
        else l=mid+1;
    }printf("! %d\n",ans);
    return 0;
}