#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,i,r,count=0;
  cin >> N;
  
  int k=0;
  while(k<N){
    cin >> i >> r ;
    
    for(int j=i ; j<=r ; j++){
    count +=1;
    }
    k++;
  }
  cout << count << endl;
}
