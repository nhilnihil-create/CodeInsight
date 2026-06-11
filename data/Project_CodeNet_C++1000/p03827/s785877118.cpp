#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  string s;
  cin >> s;
  
  int ans = 0, maxans = 0;
  rep(i,n){
    if(s[i] == 'I'){
      ans++;
    }else{
      ans--;
    }
    if(ans > maxans){
      maxans = ans;
    }
  }
  
  cout << maxans << endl;
}