#include<bits/stdc++.h>

int ans[200005];
bool chk[200005];

int main()
{
  int n,x,len;

  scanf("%d%d",&n,&x);
  len=(n*2)-1;
  if (x==1||x==len)printf("No\n");
  else
  {
    printf("Yes\n");
    ans[n]=x;
    chk[x]=true;
    ans[n-1]=x-1;
    chk[x-1]=true;
    ans[n+1]=x+1;
    chk[x+1]=true;
    if (x+2<=(2*n)-1)ans[n-2]=x+2,chk[x+2]=true;
    if (x-2>0)ans[n+2]=x-2,chk[x-2]=true;
    int ptr=1;
    while(chk[ptr])ptr++;
    for(int c=1;c<=len;c++)
    {
      if (ans[c]==0)
      {
        ans[c]=ptr;
        chk[ptr]=true;
        while(chk[ptr])ptr++;
      }
    }
    for(int c=1;c<=len;c++)printf("%d\n",ans[c]);
  }
}
