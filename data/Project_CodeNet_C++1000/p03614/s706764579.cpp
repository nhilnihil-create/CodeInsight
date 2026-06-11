#include<bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(int)n;i++)



int main(){

  int n,cnt=0;
  cin >> n;
  vector<int> p(n);
  rep(i,n){cin >> p[i];p[i]--;}
  rep(i,n){
    if (p[i]==i){
      swap(p[i],p[i+1]);
      cnt++;
    }
  }
  cout << cnt << endl;

  return 0;
}
