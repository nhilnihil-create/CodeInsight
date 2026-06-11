#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  bool beauty = false;
  if(b-a==c-b) beauty = true;
  if(beauty){
    printf("YES");
  }else{
    printf("NO");
  }
  return 0;
}