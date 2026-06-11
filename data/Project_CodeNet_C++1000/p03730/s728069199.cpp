#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(){
  int a,b,c;
  std::cin >> a>>b>>c;
  bool ok=false;
  for (int i = 1; i < 101; i++) {
    if((a*i)%b==c){
      ok=true;
    }
  }
  if(ok)std::cout << "YES" << '\n';
  else std::cout << "NO" << '\n';
  return 0;
}
