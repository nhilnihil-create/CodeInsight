#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int64_t cnt=1;
  for(int i=1;i<=N;i++){
    cnt*=i;
    if(cnt>1000000007){
      cnt%=1000000007;
    }
  }
  cout << cnt << endl;
}