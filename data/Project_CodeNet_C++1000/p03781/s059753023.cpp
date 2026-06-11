#include<bits/stdc++.h>
using namespace std;
  
int main(){
  int X;
  cin >> X;
  int ima=0;
  int i=1;
  while(ima<X){
    ima+=i;
    i++;
  }
  cout << i-1 << endl;
}
    
