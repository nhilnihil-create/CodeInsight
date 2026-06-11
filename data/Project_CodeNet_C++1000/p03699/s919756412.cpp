#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
  int N;
  cin >> N;
  int s[105];
  for(int i = 0; i < N; i++){
    cin >> s[i];
  }
  sort(s,s+N);
  int sum;
  for(int i = 0; i < N; i++){
    sum+= s[i];
  }
  if(sum%10 != 0){
    cout << sum << endl;
    return 0;
  }
  else{
    for(int i = 0; i <N; i++){
      if(s[i]%10!= 0){
        cout << sum-s[i] << endl;
        return 0;
      }
    }
  }
  cout << 0 << endl;
  return 0;
}