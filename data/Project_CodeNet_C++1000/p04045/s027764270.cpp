#include <bits/stdc++.h>
using namespace std;

int main(){
  string N;
  int K;
  cin >> N >> K;
  vector<bool> flag(10,true);
  int D;
  for(int i=0;i<K;i++){
    cin >> D;
    flag.at(D)=false;
  }
  bool carry=false;
  deque<int> ans;
  int x,j,mi;
  for(int i=0;i<=9;i++){
    if(flag.at(i)){
      mi=i;
      break;
    }
  }
  for(int i=N.size()-1;i>=0;i--){
    x=N.at(i)-'0';
    if(carry){
      x++;
      if(x==10){
        x=0;
      }else{
        carry=false;
      }
    }
    if(flag.at(x)){
      ans.push_front(x);
    }else{
      for(j=x+1;j<=9;j++){
        if(flag.at(j)){
          ans.assign(ans.size(),mi);
          ans.push_front(j);
          break;
        }
      }
      if(j==10){
        carry=true;
        for(j=0;j<x;j++){
          if(flag.at(j)){
            ans.assign(ans.size(),mi);
            ans.push_front(j);
            break;
          }
        }
      }
    }
  }
  if(carry){
    if(flag.at(1)){
      ans.push_front(1);
    }else{
      for(int i=2;i<=9;i++){
        if(flag.at(i)){
          ans.assign(ans.size(),mi);
          ans.push_front(i);
          break;
        }
      }
    }
  }
  for(int i=0;i<ans.size();i++){
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}
