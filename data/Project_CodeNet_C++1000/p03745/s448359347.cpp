#include <bits/stdc++.h>
using namespace std;

int compare(int a, int b){
   if(a>b) return -1;
   if(a==b) return 0;
   if(a<b) return 1;
}
int main() {
int N; cin >> N;
  vector<int> A(N);
  for(int i=0; i<N; i++) cin >> A.at(i);
  //増加から分ける
  int ans=0;
  int count =0;
  int cur = 0;

  for(int i=0; i<N-1; i++){
    if (count == 0 || cur == 0){
      count++;
      cur = compare(A.at(i),A.at(i+1));
      continue;
    }
    if (A.at(i) != A.at(i+1) && compare(A.at(i),A.at(i+1)) != cur){
      count = 0;
      ans++;
    }
  }
  cout << ans +1 << endl;
  
}