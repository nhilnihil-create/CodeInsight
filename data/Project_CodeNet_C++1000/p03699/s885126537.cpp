#include <bits/stdc++.h>
using namespace std;

int main() {
  int num;
  int allSum = 0;
  int kekka = 0;
  int tmp = 0;
  
  cin >> num;
  
  vector<int> vec(num);
  for(int i = 0; i < num; i++){
    cin >> vec.at(i);
    allSum += vec.at(i);
  }
  
  sort(vec.begin(), vec.end());
  
  if(allSum % 10 == 0){
    kekka = 0;
    for(int i = 0; i < num; i++){
      if(vec.at(i) % 10 == 0){
      }else{
        kekka = allSum - vec.at(i);
        break;
      }
    }
  }else{
    kekka = allSum;
  }
  
  cout << kekka;
}
