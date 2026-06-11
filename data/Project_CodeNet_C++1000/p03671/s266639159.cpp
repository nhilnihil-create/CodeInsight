#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  vector<int> ans;
  ans.push_back(a+b);
  ans.push_back(a+c);
  ans.push_back(b+c);
  printf("%d\n",*min_element(ans.begin(),ans.end()));
  return 0;
}
