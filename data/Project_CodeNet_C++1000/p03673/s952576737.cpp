#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int>a(n, 0);
  vector<int>ans;
  rep(i, n) cin >> a.at(i);
  if(n%2==1){
  rep(i, n){
    if(i%2==1){
      ans.push_back(a.at(i));
    }
    else{
      ans.insert(ans.begin(), a.at(i));
    }
    }  
  }
  else{
  rep(i, n){
    if(i%2==0){
      ans.push_back(a.at(i));
    }
    else{
      ans.insert(ans.begin(), a.at(i));
      }
    }  
  }
  rep(i, n) cout << ans.at(i) << " ";
}
