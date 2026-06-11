#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int h,w;
  cin >> h >> w;
  
  rep(i,h)rep(j,w){{
    string c;
    cin >> c;
    if (c == "snuke") {
      char g = 'Z' - 25 + j;
      cout << g << i+1 << endl;
      break;
    }
  }}
  
}