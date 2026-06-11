#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0; i<N; i++) cin >> A.at(i);
  sort(A.begin(),A.end());
  long long ans=1;
  if(N%2==0){
    int cnt=1;
    for(int i=0; i<N; i+=2){
      if(A.at(i)!=cnt || A.at(i+1)!=cnt){
        ans=0;
        break;
      }
      cnt+=2;
      ans=ans*2 % 1000000007;
    }
  }
  else{
    int cnt=2;
    for(int i=1; i<N; i+=2){
      if(A.at(i)!=cnt || A.at(i+1)!=cnt){
        ans=0;
        break;
      }
      cnt+=2;
      ans=ans * 2 % 1000000007;
    }
    if(A.at(0)!=0) ans=0;
  }
  cout << ans << endl;
}