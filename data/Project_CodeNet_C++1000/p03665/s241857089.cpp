#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t N, P;
  cin >> N >> P;
  int64_t odd=0;
  int64_t A;
  for(int64_t i=0LL; i<N; i++){
    cin >> A;
    odd+=A%2;
  }
  if(odd==0 && P==1){
    cout << 0 << endl;
  }
  else if(odd==0 && P==0){
    cout << (int64_t)pow(2, N) << endl;
  }
  else{
    cout << (int64_t)pow(2, N-1) << endl;
  }
}