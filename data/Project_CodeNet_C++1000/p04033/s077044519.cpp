#include<bits/stdc++.h>
using namespace std;

int main(){
  long long a,b;
  long long tmp;
  cin >> a >> b;
  
  if((a < 0 && b > 0) || (a > 0 && b < 0)){
    cout << "Zero";
  }else if(a > 0){
    cout << "Positive";
  }else{
    tmp = labs(b - a) + 1;
    if(tmp % 2 == 0) cout << "Positive";
    else cout << "Negative";
  }
}
