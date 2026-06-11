#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep1(i,n) for(int i=0; i+1<n; i++)

int main(){
  int N;
  scanf("%d", &N);
  
  int count = 0;
  int a = 2;
  
  while(a <= N){
    count++;
    a = a*2;
  }
  
  if(count == 0) printf("%d\n",N);
  else printf("%d\n", a/2);
  
  return 0;
}
