#include <iostream>
using namespace std;
#define rep(i,q) for(int i = 0; q > i; i++)
int main(){
  int H,W;
  cin >> H >> W;
  rep(i,H){
    rep(j,W){
      string tmp;cin >> tmp;
      if(tmp == "snuke"){
        char arupa = 'A'-0+(j);
        cout << arupa << i+1 << endl;
      }
    }
  }
 return 0; 
}