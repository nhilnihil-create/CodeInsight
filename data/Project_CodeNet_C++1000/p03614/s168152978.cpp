#include<bits/stdc++.h>
using namespace std;
int N;
bool c[101010];
int main()
{
  int N; scanf("%d", &N);
  for(int i=0; i<N; ++i)
  {
    int t; scanf("%d", &t);
    c[i] = (t == i+1);
  }
  int ans = 0;
  for(int i=0; i<N; ++i)
  {
    if(c[i])
    {
      ++ans; c[i] = c[i+1] = false;
    }
  }
  printf("%d\n", ans);
}