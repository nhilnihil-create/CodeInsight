#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N, C, K;
  cin >> N >> C >> K;
  vector<int> T(N);
  for(int i=0; i<N; i++){
    cin >> T.at(i);
  }
  sort(T.begin(), T.end());
  int ans=0;
  for(int i=0; i<N;){
    int p=1;
    for(int j=1; p<C && i+j<N; j++){
      if(T.at(i+j)<=T.at(i)+K && p<C){
        p++;
      }else{
        break;
      }
    }
    i=i+p;
    ans++;
  }
  cout << ans;
  return 0;
}