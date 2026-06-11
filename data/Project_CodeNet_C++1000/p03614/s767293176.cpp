#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int sum=0;
  bool aa=false;
  for(int i=0;i<N;i++){
    int a;
    cin >> a;
    if(a==(i+1)){
      if(aa)aa=false;
      else{
        aa=true;
        sum++;
      }
    }
    else if(aa)aa=false;
  }
  cout << sum;
}

