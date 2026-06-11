#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N, A, B;
  cin >> N >> A >> B;
  vector<int64_t> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  int64_t C = A - B;
  int64_t ok = 1000000000;
  int64_t ng = 0;
  while(ok - ng > 1){
    int64_t mid = (ok + ng) / 2;
    vector<int64_t> amari(0);
    bool clear = true;
    for(int i=0; i<N; i++){
      if(vec.at(i) > mid*B){
        amari.push_back(vec.at(i) - mid*B);
      }
    }
    int64_t cnt = 0;
    for(int i=0; i<amari.size(); i++){
      cnt += (amari.at(i) + C-1)/C;
    }
    if(cnt > mid){
      clear = false;
    }
    
    
    if(clear){
      ok = mid;
    }
    else{
      ng = mid;
    }
  }
  cout << ok << endl;
}
    