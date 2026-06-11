#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  cin >> A >> B;
  int ans;
  ans = A + B;
  if(ans<10){
    printf("%d\n",ans);
  }else{
    printf("error");
  }
  return 0;
}