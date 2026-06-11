#include <bits/stdc++.h>
using namespace std;

char str[200100];
int n,nxt[200100][26],dp[200100];

int DP(int idx) {
    if(idx<=-1) return 0;
    int &ret=dp[idx];
    if(ret!=-1) return ret;

    ret=n+1;
    for(int i=0;i<26;i++) ret = min(ret,DP(nxt[idx][i]-1)+1);
    return ret;
}
string ans;
void trace(int idx) {
    if(idx<=-1) return;
    for(int i=0;i<26;i++) if(DP(nxt[idx][i]-1)+1==DP(idx)) {
        trace(nxt[idx][i]-1);
        ans.push_back(i+'a');
        break;
    }
}
int main() {
    scanf("%d",&n);
    scanf("%s",str+1);

    int c[26]={0,};
    n=strlen(str+1);
    reverse(str+1,str+n+1);
    for(int i=1;i<=n;i++) {
        c[str[i]-'a']=i;
        for(int j=0;j<26;j++) nxt[i][j]=c[j];
    }
    memset(dp,-1,sizeof(dp));
    DP(n);
    trace(n);
    reverse(ans.begin(),ans.end());
    printf("%s\n",ans.c_str());
    
    return 0;
}
