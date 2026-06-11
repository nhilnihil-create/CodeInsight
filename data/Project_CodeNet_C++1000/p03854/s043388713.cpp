#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

void printNo(){
  cout << "NO" << endl;
  exit(0);
}

//本来はREだけど通ってしまう
int main() {
  string s;cin >> s;
  string pre = "";
  for(ll i=0;i<(ll)s.size();++i){
    if( s.at(i) != 'd' && s.at(i) != 'e' ) printNo();

    if( s.at(i) == 'd' ){
      string tmp = s.substr(i,5);
      if( tmp == "dream" ) i += 4;
      else printNo();
      pre = "dream";
    }
    else if( s.at(i) == 'e' ){
      string tmp = s.substr(i,6);
      if( tmp == "eraser" ){
        i+= 5;
        pre = "eraser";
      }
      else if( tmp.substr(0,5) == "erase" ){
        i+= 4;
        pre = "erase";
      }
      else if( tmp.at(1) == 'r' && pre == "dream" ){
        i++;
        pre = "dreamer";
      }
      else printNo();
    }
  }
  cout << "YES" << endl;
  return 0;
}