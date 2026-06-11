#include <bits/stdc++.h>

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)

#define REPISE (s,e) for(int i=s,i<e;i++)
#define REPJSE (s,e) for(int j=s,j<e;j++)

typedef long long ll;

using namespace std;

int main ()
{
  int A,B,C,Ad,Bd,Cd,res=0;

  scanf("%d %d %d",&A,&B,&C);

  while (A%2 == 0 && B%2 == 0 && C%2 == 0)
  {
    if (A == B && B == C)
    {
      res = -1;
      break;
    }
    Ad = A/2;
    Bd = B/2;
    Cd = C/2;
    A = Bd + Cd;
    B = Ad + Cd;
    C = Ad + Bd;
    res++;
  }

  printf("%d\n",res);


  return 0;
}