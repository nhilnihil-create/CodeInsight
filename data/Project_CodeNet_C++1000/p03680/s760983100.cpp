#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin>>N;
  vector<int> a(N+1),roopCheck(N+1,1);
  for(int i=0; i<N; i++) cin>>a[i+1];
  
  int now=1; roopCheck[now]=0;
  int count=0;
  bool flg = false;
  while(roopCheck[a[now]]){
    now = a[now];
    roopCheck[now]=0;
    count++;
    if(now==2){
      flg = true;
      break;
    }
  }
  
  if(flg){
    cout << count << endl;
  }else{
    cout << -1 << endl;
  }
}