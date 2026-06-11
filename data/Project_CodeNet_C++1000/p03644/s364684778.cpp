#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a; i<n; i++)
#define ll long long
#define MOD 1000000007
using namespace std;;
 
int main() {
  int N,ans =1; scanf("%d",&N); 
  while(ans<=N) {
    ans *=2;
  } 
  printf("%d\n",ans/2);
  
}