#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
int main(){
  ll K,i;scanf("%lld",&K);
  printf("50\n");
  ll A[50];fill(A,A+50,49+(K+49)/50);
  K = 49-(K+50-1)%50;
  for(i=0;i<K;i++) A[i] = A[i]-51+K;
  for(i=K;i<50;i++) A[i] += K;
  for(i=0;i<50;i++) printf("%lld ",A[i]);
  printf("\n");
}