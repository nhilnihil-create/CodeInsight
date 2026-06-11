#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long A[3];scanf("%lld %lld %lld",&A[0],&A[1],&A[2]);
  if(A[0]%2==0||A[1]%2==0||A[2]%2==0){printf("0\n");return 0;}
  sort(A,A+3);
  printf("%lld\n",A[0]*A[1]);
}