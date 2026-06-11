#include <iostream>

using namespace std;

int main(){
string A, B;
  cin >> A >> B;
  //入力終了

  //AとBの桁数
  int a = A.size(), b = B.size();
  
  //Aの方が桁数が小さい
  if(a<b)
    cout << "LESS" << endl;
  //Aの方が桁数が大きい
  else if(a>b)
    cout << "GREATER" << endl;
  //桁数は同じ
  else{
	int i = -1, j = -1;
	//文字列が同じところはスルー
    while(A[++i] == B[++j])
      //最後までいったら文字列は等しい
      if(i == a){
       cout << "EQUAL" << endl;
	   return 0;
      }
    
    if(A[i] < B[j])
      cout << "LESS" << endl;
    else
      cout << "GREATER" << endl;
  }

return 0;	
}