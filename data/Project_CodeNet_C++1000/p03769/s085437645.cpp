#include<bits/stdc++.h>
using namespace std;

long long n;
vector<int> ans;

int main() {

  int mx=100,mn=1;
  scanf("%lld",&n);
  while(n) {
    if(!(n&1)) {
      n--;
      ans.push_back(mx--);
    }
    n--;
    n/=2;
    ans.push_back(mn++);
  }
  for(int i=1;i<=100;i++) ans.push_back(i);
  printf("%d\n",ans.size());
  for(int i=0;i<ans.size();i++) {
    printf("%d ",ans[i]);
  }

}
