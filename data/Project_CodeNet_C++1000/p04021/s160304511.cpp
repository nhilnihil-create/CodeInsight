#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  vector<int> copy(N);
  for(int i=0; i<N; i++){
    copy.at(i) = vec.at(i);
  }
  sort(copy.begin(),copy.end());
  map<int,int> mp;
  for(int i=0; i<N; i++){
    mp[copy.at(i)] = i;
  }
  vector<bool> change(N);
  for(int i=0; i<N; i++){
    if(i %2 == mp[vec.at(i)] %2){
      change.at(i) = true;
    }
    else{
      change.at(i) = false;
    }
  }
  int ans = 0;
  for(int i=0; i<N-1; i++){
    if(!change.at(i)){
      if(!change.at(i+1)){
        change.at(i) = true;
        change.at(i+1) = true;  
        ans++;
      }
      else{
        swap(change.at(i),change.at(i+1));
      }
    }
  }
  cout << ans << endl;
}