#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
int H, W;
cin >> H >> W;
  
  //最上段の#
  rep(i, W+2)
    cout << '#' ;
  cout << endl;
  
  char tmp;
  rep(i, H){
    //左端の#
  cout << '#' ;
    rep(j, W){
      cin >> tmp;
      cout << tmp;
    }
    //右端の#
    cout << '#' <<endl;
  }
  
  //最下段の#
  rep(i, W+2)
    cout << '#' ;
  cout << endl;
  

return 0;
}