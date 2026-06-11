#include <bits/stdc++.h>
using namespace std;

int main(){
  int K,S,count=0;
  cin >> K >> S;
  for(int i=0;i<K+1;i++){
    for(int j=0;j<K+1;j++){
      if(0<=S-i-j && S-i-j<K+1){
          count++;
        }
    }
  }
  cout << count << endl;
} 