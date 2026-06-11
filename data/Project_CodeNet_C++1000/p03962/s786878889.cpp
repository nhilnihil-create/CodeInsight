#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){ 
  set<int> s;
  rep(i,3) {
    int a;
    cin >> a;
    s.insert(a);
  }
  
  int cnt = 0;
  for(auto i=s.begin(); i!=s.end(); ++i) {
    cnt++;
  }
  
  cout << cnt << endl;
  

}