#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007
priority_queue<int, vector<int>, greater<int> > PQ; // 昇順PQ
// priority_queue<int> PQ;

int main(){
  int a,b,c;

  scanf("%d %d %d", &a, &b, &c);

  if(a <= c && c <= b) printf("Yes\n");

  else printf("No\n");
  return 0;
}
