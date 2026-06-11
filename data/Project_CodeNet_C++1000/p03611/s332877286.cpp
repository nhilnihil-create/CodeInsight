#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i,n) cin >> a.at(i);

  int ans=0;
  int r=0;
  
  sort(a.begin(), a.end());
  
  rep(l,n){
    int left = a.at(l);
    while(r<n&&a.at(r)<=left+2){
      r++;
    }
    ans = max(ans, r-l);
  }

  cout << ans;
}