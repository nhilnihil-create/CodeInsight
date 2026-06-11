#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  map<int,int> mp;
  int MAX = 0;
  int MIN = 1e9;
  for(int i=0; i<N; i++){
    int x;
    cin >> x;
    mp[x]++;
    MAX = max(MAX,x);
    MIN = min(MIN,x);
  }
  
  bool flag = true;
  
  int now = MIN-1;
  for(auto itr = mp.begin(); itr != mp.end(); itr++){
    int x = itr->first;
    int y = itr->second;
    if(x != now+1){
      flag = false;
    }
    if(x == MIN){
      if(MAX %2 == 1){
        if(y != 2){
          flag = false;
        }
      }
      else{
        if(y != 1){
          flag = false;
        }
      }
    }
    if(x == MAX){
      if(y == 1){
        flag = false;
      }
    }
    now = x;
  }
  
  if(flag){
    cout << "Possible" << endl;
  }
  else{
    cout << "Impossible" << endl;
  }
}
    
    