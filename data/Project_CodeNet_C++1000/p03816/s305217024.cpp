#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
int main(){
  int N,i;scanf("%d",&N);
  vector<int> a(N);
  for(i=0;i<N;i++) scanf("%d",&a[i]);
  sort(a.begin(),a.end());
  a.erase(unique(a.begin(),a.end()),a.end());
  int ans = a.size();
  if(ans%2==0) ans--;
  printf("%d\n",ans);
}