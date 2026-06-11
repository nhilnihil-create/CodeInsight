#include <bits/stdc++.h>
#define int long long
using namespace std;
using Graph = vector<vector<int>>;


signed main(){
  
  string S;
  cin >> S;
  int K;
  cin >> K;
  
  string ab = "abcdefghijklmnopqrstuvwxyz";
  
  int N = (int)S.size();
  vector<int> cnt(N);
  for( int i = 0; i < N; i++ ){
    for( int j = 0; j < 26; j++ ){
      if( S.at(i) == ab.at(j) ) cnt.at(i) = j;
    }
  }
  
  
  for( int i = 0; i < N; i++ ){
    if( cnt.at(i) != 0 ){
      if( K >= 26-cnt.at(i) ){
        int hiku = 26-cnt.at(i);
        K -= hiku;
        cnt.at(i) = 0;
      }
    }
  }
  
  if( K > 0 ){
    K %= 26;
    cnt.at(N-1) += K;
  }
  
  for( int i = 0; i < N; i++ ) cout << ab.at(cnt.at(i));
  cout << endl;
                                            

  
}
