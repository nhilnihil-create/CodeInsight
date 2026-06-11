#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int ma=0;
  int s=0;
  for(int i=0;i<N;i++){
    int A,B;
    cin >> A >> B;
    if(ma<A){
      ma=A;
      s=B;
    }
  }
  cout << ma+s << endl;
  return 0;
}
