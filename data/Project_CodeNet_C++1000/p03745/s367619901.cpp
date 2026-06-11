#include <bits/stdc++.h>
using namespace std;

inline int sgn(int n){
  int ans= (n==0) ? 0
                  : n/abs(n);
  return ans;
}

int main(){
  int N;
  cin >> N;
  
  vector<int> data(N);
  for(int i=0; i<N; i++){
    cin >> data.at(i);
  }

  int ans= 0;
  int ref= 0;
  for(int left=0; left<N;){
    while(ref+1 < N && sgn(data.at(ref+1)- data.at(ref))==0){
      ref++;
    }
    int right= ref;
    while(right+1 < N && sgn(data.at(right+1)- data.at(right))* sgn(data.at(ref+1)- data.at(ref)) >= 0){
      right++;
    }

    ans++;
    left= right+ 1;
    ref = right+ 1;
  }

  cout << ans << endl;
}