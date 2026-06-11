#include <iostream>

using namespace std;

int main(void){
  int A, B, C;
  cin >> A >> B >> C;
  // 入力終了

  // Ax = By + C
  // となるx，yがあるかを全探索
  // ただし，xはBまで，yはAまで見ればOK
  
  for(int x=0; x<=B; x++){
    for(int y=0; y<=A; y++){
      if(A*x == B*y+C){
	cout << "YES" << endl;
	return 0;
      }
    }
  }

  // 該当なし
  cout << "NO" << endl;

  return 0;
}
