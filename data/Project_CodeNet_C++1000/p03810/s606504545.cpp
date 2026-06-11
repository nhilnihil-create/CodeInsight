#include <bits/stdc++.h>
using namespace std;

const int N = 111111;

int A[N] , n;

void print(int who) {
  if(who) puts("First");
  else puts("Second");
  exit(0);
}

int gcd(int x , int y) {
  return (!y) ? x : gcd(y , x % y);
}

int check(void) {
  for(int i = 1;i <= n;++ i) if(A[i] == 1) return 1;
  return 0;
}

int main(void) {
  cin >> n;
  int lsk = 0;
  for(int i = 1;i <= n;++ i) {
    cin >> A[i];
    lsk += A[i] & 1;
  }
  int pg = 1 , dead = check();
  while(1) {
    if((n - lsk) & 1) print(pg);
    if(lsk > 1 || dead) print(pg ^ 1);
    for(int i = 1;i <= n;++ i) if(A[i] & 1) -- A[i];
    int G = 0;
    for(int i = 1;i <= n;++ i) G = gcd(G , A[i]);
    for(int i = 1;i <= n;++ i) A[i] /= G;
    lsk = 0;
    for(int i = 1;i <= n;++ i) lsk += (A[i] & 1);
    dead = check();
    pg ^= 1;
  }
}
