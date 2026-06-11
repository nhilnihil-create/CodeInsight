#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  string sa,sb,sc;
  cin>>sa>>sb>>sc;

  char turn ='a';
  char winner;

  while(1){

    if(turn == 'a'){
      if(!sa.empty()){
        turn=sa.front();
        sa.erase(0,1);
      }
      else{
        winner='a';
        break;
      }
    }else if(turn == 'b'){
      if(!sb.empty()){
        turn=sb.front();
        sb.erase(0,1);
      }
      else{
        winner='b';
        break;
      }
    }else if(turn == 'c'){
      if(!sc.empty()){
        turn=sc.front();
        sc.erase(0,1);
      }
      else{
        winner='c';
        break;
      }
    }
  }

  if(winner=='a')
    cout<<'A'<<endl;
  else if(winner=='b')
    cout<<'B'<<endl;
  else if(winner=='c')
    cout<<'C'<<endl;

  return 0;
}