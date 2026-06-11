// #include <bits/stdc++.h>
#include <iostream>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repr(i,n) for (int i = 0; i < (f); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MAX = 100000;

int main() {
  int n,a,b;
  int sum = 0;
  int total_o = 0;

  cin >> n >> a >> b;
  char s[MAX];
  cin >> s;

  rep(i,n){
    switch (s[i])
    {
    case 'a':
      if (sum < (a + b)){
        cout << "Yes" << endl;
        sum++;
      }else cout << "No" << endl;
      break;
    
    case 'b':
      if (sum < (a + b) && total_o < b){
        cout << "Yes" << endl;
        sum++;
        total_o++;
      }else cout << "No" << endl;
      break;
    
    default:
      cout << "No" << endl;
      break;
    }
  }
  
  return 0;
}