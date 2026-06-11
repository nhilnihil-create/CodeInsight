#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N, M;
  cin >> N >> M;
  
  vector<int> mati(N);
  
  for( int i=0 ; i < M ; i++ ){
    int a, b;
    cin >> a >> b;
    mati.at(a-1)++;
    mati.at(b-1)++;
  }
  
  for( int i=0 ; i < N ; i++ ){
    cout << mati.at(i) << endl;
  }
}