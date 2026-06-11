#include <bits/stdc++.h>
using namespace std;

int main() {
  int num;
  int cntOne = 0;
  int cntTwo = 0;
  int cntFor = 0;
  string kekka = "No";
  
  cin >> num;
  vector<int> vec(num);
  vector<int> chk(num);
  
  int tmp;
  for(int i = 0; i < num; i++){
    cin >> tmp;
    vec.at(i) = tmp;
    
    if(tmp % 4 == 0){
      // 4の倍数
      vec.at(i) = 4;
      cntFor++;
    }else if(tmp % 2 == 0){
      // 2の倍数
      vec.at(i) = 2;
      cntTwo++;
    }else{
      // 1の倍数
      vec.at(i) = 1;
      cntOne++;
    }
  }
  
  if(cntTwo == 0){
    // 1と4  141 , 144 , 444
    // 4が一つ少ないか、4が同数以上ならおっけ
    if(cntOne <= cntFor+1) kekka = "Yes";
  }else{
    // 1,2,4 14222 
    // 1と4 が同数あればおっけ
    if(cntOne <= cntFor) kekka = "Yes";
  }
  
  cout << kekka;
}
