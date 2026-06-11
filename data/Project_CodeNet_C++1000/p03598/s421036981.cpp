#include <bits/stdc++.h>
using namespace std;
int main() {
 int N,K,x;
 int a=0;
 cin >> N >> K;
  for(int i; i<N ; i++){
   cin >> x;
    if(K-x>x){
      a = a+2*x;
    }else{
      a = a+(K-x)*2;
    }
  }
  cout << a << endl;
}