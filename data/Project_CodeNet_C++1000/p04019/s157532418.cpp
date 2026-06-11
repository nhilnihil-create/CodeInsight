#include <iostream>
#include <map>

#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  string S;
  cin >> S;
  // 入力終了

  map<char, int> count;
  rep(i, S.size() ){
    count[ S[i] ]++;
  }

  // 東に移動するが，西には移動しない
  if(count['E'] > 0 && count['W'] == 0){
    cout << "No" << endl;
    return 0;
  }

  // 西に移動するが，東には移動しない                                                     
  if(count['W'] > 0 && count['E'] == 0){
    cout << "No" << endl;
    return 0;
  }

  // 南に移動するが，北には移動しない                                                     
  if(count['S'] > 0 && count['N'] == 0){
    cout << "No" << endl;
    return 0;
  }

  // 北に移動するが，南には移動しない                                                     
  if(count['N'] > 0 && count['S'] == 0){
    cout << "No" << endl;
    return 0;
  }

  // 上記以外ならOK
  cout << "Yes" << endl;
  
  
  return 0;
}
