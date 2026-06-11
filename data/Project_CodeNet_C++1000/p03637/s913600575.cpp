#include<bits/stdc++.h>
 
using namespace std;

int main(){
  // 奇数の数: a, 4の倍数の数: b
  // 偶数で４の倍数でない: c
  int N;
  cin >> N;
  int a=0, b=0, c=0;
  for(int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    if(tmp % 4 == 0){
      b++;
    } else if(tmp % 4 == 2){
      c++;
    } else {
      a++;
    }
  }
  
  string ans;
  if(b == 0){
    if(a == 0 && c >= 2){
      ans = "Yes";
    } else { 
      ans = "No";
    }
  } else {
    if(a <= b){
      ans = "Yes";
    } else if( a == b+1 && c == 0) { 
      ans = "Yes";
    } else { 
      ans = "No";
    }
  }
  
  cout << ans << endl;
    
}