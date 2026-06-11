#include<bits/stdc++.h>
using namespace std;

int main()
{
int K,S;scanf("%d %d",&K,&S);int ans=0;
for(int X=0;X<K+1;X++)for(int Y=0;Y<K+1;Y++)if(S-X-Y<K+1&&S-X-Y>-1)ans++;
printf("%d\n",ans);
}