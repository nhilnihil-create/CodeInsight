#include<cstdio>
#include<cstring>
using namespace std;
int nxt[200010],dp[200010],ans[200010],to[200010];
char ch[200010];
int main() {
    scanf("%s",ch+1);
    int len=strlen(ch+1);
    for (int i=1; i<=26; i++) nxt[i]=len+1;
    for (int i=1,ii=len+1; i<=ii; i++) dp[i]=2019201920/2;
    dp[len+2]=0;
    for (int i=len; i>=1; i--) {
        nxt[ch[i]-'a'+1]=i;
        for (int j=1; j<=26; j++)
            if (dp[nxt[j]+1]+1<dp[i]) {
                dp[i]=dp[nxt[j]+1]+1;
                ans[i]=j;
                to[i]=nxt[j]+1;
            }
    }
    int num=1;
    while (num<=len) {
        printf("%c",ans[num]+'a'-1);
        num=to[num];
    }
    return 0;
}