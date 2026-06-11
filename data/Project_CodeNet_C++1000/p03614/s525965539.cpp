#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, cnt=0;
  cin >> n;
  int prev=-1;
  for(int i=1;i<=n;i++){
    int p;cin >> p;
    if(i==p){
      if(prev!=i-1){
        cnt++;
        prev=i;
      }
    }
  }
  cout << cnt << endl;
}
