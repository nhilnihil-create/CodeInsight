#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
char s[N];
int l[N],r[N],cnt;
int L[N],R[N];
set<char>jh;
string ans;
bool vis[30];
int main()
{
    scanf("%s",s+1);int jl=0;
    int len=strlen(s+1);
    for(int i=len;i>=1;i--){
        if(jh.size()==0)jl=i;
        jh.insert(s[i]);
        if(jh.size()==26){
            r[++cnt]=jl;
            l[cnt]=i;jh.clear();
        }
    }
    int n=cnt;
    for(int i=1,j=cnt;j>=1;j--,i++){
        L[i]=l[j];R[i]=r[j];
    }
    if(cnt==0){
        for(int i=1;i<=len;i++){
            vis[s[i]-'a']=1;
        }int p;
        for(int i=0;i<26;i++)if(vis[i]==0){p=i;break;}
        ans+=char(p+'a');cout<<ans<<endl;
        return 0;
    }
    int p=1;
    memset(vis,0,sizeof(vis));
    for(int j=1;j<L[1];j++)vis[s[j]-'a']=1;
    int pos=0;
    for(int j=0;j<26;j++)if(!vis[j]){pos=j;break;}
    ans+=char(pos+'a');
    while(p<=len&&s[p]!=pos+'a')p++;
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        p++;
        for(int j=p;j<=R[i];j++){
            vis[s[j]-'a']=1;
        }
        for(int j=0;j<26;j++)if(!vis[j]){pos=j;break;}
        ans+=char(pos+'a');
        while(p<=len&&s[p]!=pos+'a')p++;
    }
    cout<<ans<<endl;
}
