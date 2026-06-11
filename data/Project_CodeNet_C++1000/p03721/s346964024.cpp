#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<int64_t> vec(100000,0);
  int64_t N, K;
  cin >> N >> K;
  for(int i = 0; i < N; i++){
    int a,b;
    cin >> a >> b;
    vec[a] += b;
  }
  
  for(int i = 0; true; i++){
    K -= vec[i];
    if(K <= 0){
      cout << i << endl;
     return 0;
    }
  }
  
}