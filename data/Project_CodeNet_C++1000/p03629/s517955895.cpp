#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+300;
int l[maxn];
int r[maxn];
int ans;
char s[maxn];
int vis[30];
int ta;
char ts;
int cnt;
int cur;
int len;
void work()
{
    for(int i=cur; i>=0; --i) {
        memset(vis,0,sizeof(vis));
//        int now=26;
        for(int j=ta; j<=r[i]; j++)
            vis[s[j]-'a']=1;
        for(int j=0; j<26; j++)
            if(vis[j]==0) {
                printf("%c",j+'a');
                ts=j+'a';
                break;
            }
        for(int j=ta; j<=len-1; j++)if(s[j]==ts) {
                ta=j+1;
                break;
            }
    }
}
int main() {
//    freopen("in.txt","r",stdin);
    scanf("%s",s);
    len=strlen(s);
    r[0]=len-1;
    for(int i=len-1; i>=0; i--) {
        if(vis[s[i]-'a']==0) {
            cnt++;
            vis[s[i]-'a']=1;
            if(cnt==26) {
                l[cur++]=i;
                r[cur]=i-1;
                cnt=0;
                memset(vis,0,sizeof(vis));
            }
        }
    }
    l[cur]=0;
    work();
    return 0;
}
/*
abcdefghijklmnopqrstuvwxyz
*/
