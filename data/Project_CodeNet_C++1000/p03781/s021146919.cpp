#include<bits/stdc++.h>
using namespace std;

int main(){
  int X;
  cin >> X;
  int Now=0;
  int Ans=0;
  for(int i=1; i<=X; i++){
    Now+=i;
    if(Now>=X){
      Ans=i;
      break;
    }
  }
  cout << Ans << endl;
}