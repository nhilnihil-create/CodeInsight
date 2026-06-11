#include <iostream>
#include <map>

using namespace std;

int main(){
  int N, A, B;
  cin >> N >> A >>B;
  string S;
  cin >> S;
  //入力終わり

  int sum = 0;
  //海外の人の予選通過
  int bn = 1; 

  for(int i=0; i<N; i++){
    //学生でなければ飛ばす
    if(S[i] == 'c'){
      cout << "No" << endl;
      continue;
    }
    //予選通過人数がA+B人に満たない
    if(sum < A+B){
      if(S[i] == 'a'){
	cout << "Yes" << endl;
	sum++;
      }
      else if(S[i] == 'b'){
	//海外の予選通過人数がB人以下
	if(bn <= B){
	  cout << "Yes" << endl;
	  bn++;
	  sum++;
	}
	else
	  cout << "No" << endl;
      }
    }
    //A+B人の予選通過が決定した状態
    else
      cout << "No" << endl;
    
  }


  return 0;
}
