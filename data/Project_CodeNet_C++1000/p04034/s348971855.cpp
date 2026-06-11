#include<bits/stdc++.h>
//#include"atcoder/all"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
//using namespace atcoder;
int main(){
  int N,M,i,x,y;scanf("%d%d",&N,&M);
  int ball[N];fill(ball,ball+N,1);
  bool red[N] = {};red[0] = true;
  for(i=0;i<M;i++){
    scanf("%d%d",&x,&y);x--;y--;
    ball[x]--;ball[y]++;
    red[y] |= red[x];
    red[x] &= ball[x]>0;
  }
  printf("%d\n",accumulate(red,red+N,0));
}