#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M,K;
  cin >> N >> M >> K;

  if(K==0){
    cout << "Yes" << endl;
    return 0;
  }

  for(int i=0;i<=N;i++){
    for(int j=0;j<=M;j++){
      int tmp=i*j+(N-i)*(M-j);
      if(tmp==K){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;

  return 0;
}