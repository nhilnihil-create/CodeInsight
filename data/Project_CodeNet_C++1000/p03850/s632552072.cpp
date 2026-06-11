#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long LL;

const LL Maxn = 100010;

LL A[Maxn]; char ch[Maxn]; LL N;

LL Sum[Maxn];
LL Add[Maxn];


int main()
{
  scanf("%lld",&N); scanf("%lld",&A[0]); ch[0]='+';
  for(LL i=1;i<N;i++)
  {
    char c=getchar(); while(c!='+' && c !='-') c=getchar();
    ch[i]=c; scanf("%lld",&A[i]);
  }

  for(LL i=0;i<N;i++) Add[i]=Add[i-1]+A[i];
  for(LL i=0;i<N;i++) Sum[i]=Sum[i-1]+A[i]*((ch[i]=='+') ? 1 : -1);

  LL nx=N; LL ans=Sum[N-1];

  for(LL i=N-1;i>=0;i--) if(ch[i]=='-')
  {
    if(nx!=N) ans=max(ans,Sum[i-1]-(Add[nx-1]-Add[i-1])+(Add[N-1]-Add[nx-1]));
    nx=i;
  }
  return printf("%lld\n",ans),0;
}