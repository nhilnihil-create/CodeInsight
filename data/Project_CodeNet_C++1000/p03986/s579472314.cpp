#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map> 
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)



int main(){
  string s;
  cin >> s;
  int S = 0,T = 0;
  int ans = s.size();
  rep(i,s.size()){
     if (s[i] == 'S') S++;
     if (s[i] == 'T'){
        if (S > 0){
           S--;
           ans -=2;
        }
     }
  }
  cout << ans << endl;

   return 0;
}

