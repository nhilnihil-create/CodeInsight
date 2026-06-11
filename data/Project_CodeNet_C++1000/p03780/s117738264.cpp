#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int N,K;
int a[5000];

//a_nを除いたカードで数が作れるか
bool jud(int n){
  bool dp[5001];
  fill(dp,dp+5001,false);
  dp[0] = true;
  for(int i=0;i<N;i++){
    if(i == n) continue;

    for(int j=K;j>=0;j--){
      if(dp[j] && j + a[i] <= K){
        dp[j + a[i]] = true;
      }
    }
  }

  for(int i=max(0,K-a[n]);i<K;i++){
    if(dp[i]){
      return true;
    }
  }

  return false;
}

int bs(int a, int b){
  int p = (a + b) / 2;
  bool j = jud(p);

  if(a == b){
    if(a == 0 && j) return -1;
    else if(a == N-1 && j == 0) return N-1;
    else if(j) return a-1;
    else if(!j) return a;
  }
  else {
    if(j){
      return bs(a,p);
    } else {
      return bs(p+1,b);
    }
  }
}

//======================================================
int main(){
  cin >> N >> K;
  for(int i=0;i<N;i++) cin >> a[i];
  sort(a,a+N);

  //一番右の不必要
  cout << bs(0,N-1) + 1 << endl;
  return 0;
}