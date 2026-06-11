#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  int a,b;

  scanf("%d %d", &a, &b);
  if(a == b) printf("Draw\n");
  else if(a == 1) printf("Alice\n");
  else if(b == 1) printf("Bob\n");
  else if(a < b) printf("Bob\n");
  else printf("Alice\n"); 

  return 0;
}