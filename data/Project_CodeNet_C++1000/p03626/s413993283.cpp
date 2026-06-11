
#include <bits/stdc++.h>
#define M0D 1000000007
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;

int main(){

  int N,line[54],j=0;
  long long ans=1;
  cin >> N;
  string S1,S2;
  cin >> S1;
  cin >> S2;
  rep(i,54) line[i] = 0;
  for(int i=0; i<S1.size()-1; i++){
    if(S1[i]==S1[i+1]){
      line[j] = 1;
      i++;
    } else {
      line[j] = 2;
    }
    j++;
  }
  if(S1[S1.size()-1]!=S1[S1.size()-2]) line[j] = 2;
  if(line[0]==1) ans *= 6;
  else ans *= 3;
  for(int i=1;i<54;i++){
    if(line[i]==0) break;
    if(line[i-1]==1 && line[i]==1){
      ans *= 3;
      ans %= M0D;
    }
    if(line[i-1]==1 && line[i]==2) ans *= 1;
    if(line[i-1]==2 && line[i]==1){
      ans *= 2;
      ans %= M0D;
    }
    if(line[i-1]==2 && line[i]==2){
      ans *= 2;
      ans %= M0D;
    }
  }
  cout << ans << endl;
  return 0;
}
