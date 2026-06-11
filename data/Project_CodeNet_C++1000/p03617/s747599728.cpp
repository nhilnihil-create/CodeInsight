#include<bits/stdc++.h>
#define INF 100000000000000000
using namespace std;

int main()
{
  long long Q,H,S,D;scanf("%lld %lld %lld %lld",&Q,&H,&S,&D);
  H=min(Q*2,H);S=min(H*2,S);D=min(S*2,D);
  long long N;scanf("%lld",&N);
  printf("%lld",N/2*D+N%2*S);
}