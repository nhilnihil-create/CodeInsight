#include<bits/stdc++.h>
using namespace std;

int s[100005];

int main() {
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%d",s+i);
  int ans = 0;
  if(s[1] == 1) {
    swap(s[1],s[2]);
    ans++;
  }
  for(int i=2;i<=n;i++) {
    if(s[i] == i) {
      swap(s[i], s[i+1]);
      ans++;
    }
  }
  printf("%d\n",ans);
}
