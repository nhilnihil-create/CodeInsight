#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int c2=0;
  int c4=0;
  for(int i=0;i<N;i++){
    int64_t a;
    cin >> a;
    if(a%4==0){
      c4++;
    }else if(a%2==0){
      c2++;
    }
  }
  if(c2==0){
    if(c4>=N/2){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }else if(c2==N){
    cout << "Yes" << endl;
  }else{
    if(c4>=(N-c2+1)/2){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
  return 0;
}
