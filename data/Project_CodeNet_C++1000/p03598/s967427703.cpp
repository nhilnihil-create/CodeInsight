#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K,total;
  cin >> N >> K;
  total=0;
  for(int i=0;i<N;i++){
    int B,x;
    cin >> x;
    if(x-K<=0){
      if(-2*(x-K)>=x*2)total+=x*2;
      else total+=-2*(x-K);
    }
    else{ if(2*(x-K)>=x*2)total+=x*2;
          else total+=2*(x-K);
        }
  }
  cout << total << endl;
}
