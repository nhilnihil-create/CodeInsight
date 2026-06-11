#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
typedef long long ll;


int main(){
  string s;
  cin >>s;
  int n = s.size();
  int ans = 110, ans_temp, left;
  string letter = "abcdefghijklmnopqrstuvwxyz";
  
  rep(j, n){
    left = -1, ans_temp = -1;
    rep(i, n){
      if(s.at(i) == s.at(j)){
        ans_temp= max(abs(i-left-1), ans_temp);
        left = i;
      }
    }
      ans_temp=max(ans_temp, n-1-left);
      ans=min(ans, ans_temp);
    }
    cout << ans;
  }

