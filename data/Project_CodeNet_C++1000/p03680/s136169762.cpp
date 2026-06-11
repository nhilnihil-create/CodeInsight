#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N;
  cin >> N;
  
  vector<int> lump(N);
  for( int i=0 ; i < N ; i++ ){
    cin >> lump.at(i);
  }
  
  int num = 1;
  for( int i=0 ; i<N ; i++ ){
    num = lump.at(num-1);
    if( num == 2 ){
      cout << i+1 << endl;
      break;
    }
  }
  if( num != 2 )  cout << "-1" << endl;
}     