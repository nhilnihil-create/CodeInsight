#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
  int N;
  vector<int>v;
  cin >> N;
  for(int i = 1;i <= N;i++){
    if(N - i >= 0){
      N -= i;
      v.pb(i);
    }
  }
  int cnt = 1;
  for(int i = v.size() - 1;i >= 0;i--,cnt++){
    if(N >= cnt){
      cout << v[i] + 1 << endl;
    }else{
      cout << v[i] << endl;
    }
  }
  return 0;
}
