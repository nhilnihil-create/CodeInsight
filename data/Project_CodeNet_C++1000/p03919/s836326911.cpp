#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int h,w;
  cin >> h >> w;
  string s;
  rep(i,h){
    for(char c = 'A';c < 'A'+w;++c){
      cin >> s;
      if(s == "snuke"){
        cout << c << i+1 << endl;
        return 0;
      }
      else s = "";
    }
  }
  return 0;
}
