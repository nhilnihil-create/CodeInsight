#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >>n;
  long long s=1;
  for (int i=1;i<=n;i++){
    s*=i;
    if(s>=(1000000000+7)){
      s=s%(1000000000+7);
    }
  }
  cout << s <<endl;
}
