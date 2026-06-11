#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  sort(A.begin(),A.end());
  int cnt = 0,i=0;
  for(int j=0;j<N;j++){
    if(j==N-1){
      cnt += (j-i+1)%2;
      cout << cnt << endl;
      return 0;
    }
    if(A[j]!=A[j+1]){
      cnt += (j-i+1)%2;
      i = j + 1;
    }
  }
}