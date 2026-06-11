#include<iostream>
#include<vector>
using namespace std;
int main(){
  int x,i;
  cin >> x;
  for(i=1;x>i*(i+1)/2;i++);
  printf("%d",i);
}