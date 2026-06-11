#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int>p(n*3);
  for(int i=0,l=n*3;i<l;i++)
    cin >> p.at(i);
  sort(p.begin(),p.end(),greater());
  int64_t ans=0;
  for(int i=1;i<2*n;i+=2)
    ans+=p.at(i);
  cout << ans << endl;
  return 0;
}