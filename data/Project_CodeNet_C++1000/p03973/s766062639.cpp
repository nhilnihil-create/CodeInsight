#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N;
  cin >> N;
  vector<int64_t> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  int64_t P = 2;
  int64_t cnt = vec[0]-1;
  for(int i=1; i<N; i++){
    if(vec[i] == P){
      P++;
    }
    cnt += (vec[i]-1)/P;
    //cout << cnt << endl;
  }
  cout << cnt << endl;
}