#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
 int n;
 cin >>n;
 vector<int> a(n);
 rep(i,n) {
  cin>>a.at(i);
  }
  
  vector<int> b(n);
  vector<int> c(n);
  
  rep(i,n) {
   b.at(i) = a.at(i)+1;
   c.at(i) = a.at(i)-1;
   }
  
  a.insert(a.end(),b.begin(),b.end());
  a.insert(a.end(),c.begin(),c.end());
  
  sort(a.begin(),a.end());
  int ans = 1;
  int count = 1;
  for(int i = 0;i<a.size()-1;i++) {
    if(a.at(i) == a.at(i+1)) {
    count++;
     }
     else {
      ans = max(ans,count);
      count = 1;
      }
   }
  
  cout << ans;

}