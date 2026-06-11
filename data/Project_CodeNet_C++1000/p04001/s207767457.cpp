#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int64_t sum=0, size, flag=0, save=0;
  size = S.size();
  
  vector<int> A(size);
  for(int i=0;i<size;i++){
    A.at(i) = (S.at(i) - '0');
  }
  
  for(int tmp=0;tmp < (1 << 10);tmp++){
    bitset<10> p(tmp);
    if(p.test(size-1))
      break;
    for(int i=0;i<size-1;i++){
      if(p.test(i)){
        while(flag > 0){
          save += A.at(i-flag);
          save *= 10;
          flag--;
        }
        save += A.at(i);
        sum += save;
        save = 0;
      }else{
        flag++;
      }
    }
    while(flag > 0){
      save += A.at(size-1-flag);
      save *= 10;
      flag--;
    }
    save += A.at(size-1);
    sum += save;
    save = 0;
  }
  cout << sum << endl;
}