#include<bits/stdc++.h>
using namespace std;

char s[202000];
int n,f[202000],nex[202000][26],z,c;

void dfs(int x,int aim){
  if (aim<0) return;
  for (int i=0;i<26;++i)
    if (f[nex[x][i]+1]<aim){
      printf("%c",i+'a');
      dfs(nex[x][i]+1,aim-1);
      return;
    }
}

int main(){
  cin>>s+1;
  n=strlen(s+1);
  for (int i=0;i<26;++i) nex[n+1][i]=n+1;
  z=0,c=0; f[n+2]=-1;
  for (int i=n;i;--i){
    z|=1<<(s[i]-'a');
    if (z==(1<<26)-1) ++c, z=0;
    f[i]=c;
    memcpy(nex[i],nex[i+1],sizeof nex[i]);
    nex[i][s[i]-'a']=i;
  }
  dfs(1,f[1]);
  puts("");
}
