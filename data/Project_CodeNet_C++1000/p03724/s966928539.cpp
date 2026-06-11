#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  map<int,int> mp;
  for(int i=0; i<2*M; i++){
    int x;
    cin >> x;
    if(mp.count(x)){
      mp[x]++;
    }
    else{
      mp[x] = 1;
    }
  }
  bool flag = true;
  for(auto itr = mp.begin(); itr != mp.end(); itr++){
    if(itr->second %2 != 0){
      flag = false;
    }
  }
  
  if(flag){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}