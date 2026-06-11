#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int mid=0, mval=0;
  for(int i=0; i<N; i++){
    int a, b;
    cin >> a >> b;
    if(a>mid){
      mid=a;
      mval=b;
    }
  }
  cout << mid+mval << endl;
  return 0;
}