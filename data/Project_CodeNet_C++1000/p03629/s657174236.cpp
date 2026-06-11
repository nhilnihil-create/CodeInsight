#include<cstdio>
#include<cstring>
using namespace std;
const int N=200005;
char s[N];
int last[26],n,f[N],ans[N],nxt[N];
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    memset(f,0x3f,sizeof f);
    for (int i=0;i<26;++i) last[i]=n+1;
    f[n+2]=0;
    for (int i=n;i;--i){
        last[s[i]-'a']=i;
        for (int j=0;j<26;++j)
            if (f[last[j]+1]+1<f[i]){
                f[i]=f[last[j]+1]+1;
                ans[i]=j;
                nxt[i]=last[j]+1;
            }
    }
    int i=1;
    while (i<=n){
        printf("%c",ans[i]+'a');
        i=nxt[i];
    }
    return 0;
}