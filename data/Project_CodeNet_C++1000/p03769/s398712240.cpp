#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
const int maxn = 105;
typedef long long ll;

int main() {
#ifdef DEBUG
  freopen("in.cpp","r",stdin);
#endif
  ll n;
  cin>>n;
  n++;
  vector<int>op;
  while(n>1){
    if(n&1){
      n--;
      op.push_back(1);
    } else {
      op.push_back(0);
      n>>=1;
    }
  }
  int cur = 0;
  vector<int>ans;
  for(int i=op.size()-1;i>=0;i--) {
    ++cur;
    if(op[i])ans.insert(ans.begin(),cur);
    else ans.push_back(cur);
  }
  for (int i=1;i<=cur;i++) ans.push_back(i);
  cout<<ans.size()<<endl;
  for(int i = 0; i < ans.size();i++){
    cout<<ans[i];
    if(i+1<ans.size())cout<<' ';
    else cout<<endl;
  }
  return 0;
}
