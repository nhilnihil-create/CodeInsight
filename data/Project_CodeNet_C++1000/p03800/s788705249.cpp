#include <bits/stdc++.h>
#define L long long

using namespace std;

L n;
char st[200010];
L a[200010];

void go(){
   L i;
   for(i=2;i<n;i++)
   {
      a[i]=a[i-1]^a[i-2]^st[i-1];
   }
   a[n]=a[0];
   a[n+1]=a[1];
   a[n+2]=a[2];
   if(a[n]==a[n-1]^a[n-2]^st[n-1])
      if(a[n+1]==a[n]^a[n-1]^st[n])
      {
         for(i=0;i<n;i++)
         {
            printf("%c",a[i]?'W':'S');
         }
         exit(0);
      }
   /*for(i=0;i<n;i++)
   {
      printf("%c",a[i]?'W':'S');
   }
   puts("");*/
}

int main()
{
   scanf("%lld",&n);
   scanf("%s",st);
   L i;
   for(i=n;i<2*n;i++)
   {
      st[i]=st[i-n]=st[i-n]=='o'?0:1;
   }
   a[0]=a[n]=1;
   go();
   a[1]=a[n+1]=1;
   go();
   a[0]=a[n]=0;
   go();
   a[1]=a[n+1]=0;
   go();
   puts("-1");
}