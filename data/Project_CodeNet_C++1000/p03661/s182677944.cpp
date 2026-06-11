#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n;
  cin>>n;
  vector<int64_t> a(n);
  vector<int64_t> A(n);
  vector<int64_t> ans(n-1);
  for(int64_t i=0;i<n;i++){
    cin>>a.at(i);
  }
  A.at(0)=a.at(0);
  for(int i=1;i<n;i++){
   A.at(i)=A.at(i-1)+a.at(i);
  }
  for(int i=0;i<n-1;i++){
   ans.at(i)=abs(A.at(i)-(A.at(n-1)-A.at(i)));
  }
  sort(ans.begin(),ans.end());
  cout<<ans.at(0)<<endl;
}