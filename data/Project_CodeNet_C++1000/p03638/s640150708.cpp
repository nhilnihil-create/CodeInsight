#include<bits/stdc++.h>
using namespace std;

int main(){
  int H, W, N;
  cin >> H >> W >> N;
  vector<int> A;
  for(int i=0; i<N; i++){
    int a; cin >> a;
    for(int j=0; j<a; j++){
      A.push_back(i+1);
    }
  }
  for(int i=0; i<H; i++){
    if(i%2==0){
      for(int j=0; j<W; j++){
          cout << A[i*W+j] << " ";
      }
    }
    else{
      for(int j=W-1; j>=0; j--){
        cout << A[i*W+j] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}