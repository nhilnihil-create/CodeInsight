#include<bits/stdc++.h>
using namespace std;

int main() {
  int num;
  int tmp,tmp2;
  int cnt = 0;
  
  cin >> num;
  
  map<int,int> m;
  for(int i = 0 ;i < num; i++){
    cin >> tmp;
    tmp--;
    
    m[i] = tmp;
  }
  
  int me,you;
  for(auto itr : m){
    me = itr.first;
    you = itr.second;
    
    auto sh = m.find(you);
    if(sh->second == me){
      cnt++;
    }
  }
  
  cout << cnt / 2;
}
