#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(){
  int n,a,b;
  std::cin >> n >>a >>b;

  int d=0;
  int arank=0;
  rep(i,n){
      char c;
      bool ok=false;
      std::cin >> c;

      if(c=='b'){
        arank++;
        if(arank<=b && d<a+b){ok=true;}
      }else if(c=='a'){
        if(d<a+b)ok=true;
      }

      if(ok){std::cout << "Yes" << '\n';d++;}
      else std::cout << "No" << '\n';


  }

  return 0;
}
