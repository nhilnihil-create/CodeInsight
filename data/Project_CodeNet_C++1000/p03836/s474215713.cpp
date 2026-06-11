#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
int main(){
  int sx,sy,tx,ty;
  cin>>sx>>sy>>tx>>ty;
  string answer;
  for(int i=0;i<tx-sx;i++) answer+='R';
  for(int i=0;i<ty-sy;i++) answer+='U';
  for(int i=0;i<tx-sx;i++) answer+='L';
  for(int i=0;i<ty-sy+1;i++) answer+='D';
  for(int i=0;i<tx-sx+1;i++) answer+='R';
  for(int i=0;i<ty-sy+1;i++) answer+='U';
  answer+='L';
  answer+='U';
  for(int i=0;i<tx-sx+1;i++) answer+='L';
  for(int i=0;i<ty-sy+1;i++) answer+='D';
  answer+='R';
  cout<<answer<<endl;
  
  return 0;
}