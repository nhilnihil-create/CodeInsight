#include<bits/stdc++.h>
using namespace std;

const int MAX = 5050;
bool dp1[MAX][MAX];
bool dp2[MAX][MAX];

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  
  dp1[0][0] = true;
  dp2[0][0] = true;
  
  for(int i=0; i<N; i++){
    for(int j=0; j<=K; j++){
      if(dp1[i][j]){
        dp1[i+1][j] = true;
        if(j + vec[i] <= K){
          dp1[i+1][j + vec[i]] = true;
        }
      }
    }
  }
  
  reverse(vec.begin(),vec.end());
  
  for(int i=0; i<N; i++){
    for(int j=0; j<=K; j++){
      if(dp2[i][j]){
        dp2[i+1][j] = true;
        if(j + vec[i] <= K){
          dp2[i+1][j + vec[i]] = true;
        }
      }
    }
  }
  
  
  reverse(vec.begin(),vec.end());
  
  int ans = N;
  
  for(int i=0; i<N; i++){
    bool need = false;
    vector<int> sum(MAX,0);
    for(int j=0; j<MAX; j++){
      if(dp2[N-i-1][j]){
        sum[j] = 1;
      }
    }
    for(int j=0; j<MAX-1; j++){
      sum[j+1] += sum[j];
    }
    for(int j=0; j<K; j++){
      if(!dp1[i][j]){
        continue;
      }
      if(j + vec[i] >= K){
        need = true;
        continue;
      }
      if(sum[K-j-1] != sum[K-vec[i]-j-1]){
        need = true;
      }
    }
    if(need){
      ans--;
    }
  }
  cout << ans << endl;
}