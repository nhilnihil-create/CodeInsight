#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i=0; i<n; i++){
    cin >>a.at(i);
  }
  long long sum1=a.at(0);
  long long sum2=a.at(0);
  long long op1 = 0;
  long long op2 = 0;
  
  if (sum1<=0){
    sum1=1;
    op1 += -1*a.at(0)+1;
  }
  if (sum2>=0){
    sum2=-1;
    op2 += a.at(0)+1;
  }
  for (int j = 1; j<n; j++){
    if (sum1>0){
      sum1 += a.at(j);
      if (sum1 >= 0){
        op1 += (sum1 + 1);
        sum1 = -1;
      }
    }
    else{
      sum1 +=a.at(j);
      if (sum1<=0){
        op1 += (-1*sum1 + 1) ;
        sum1 =1 ;
      }
    }
    
    if (sum2>0){
      sum2 += a.at(j);
      if (sum2 >= 0){
        op2 += (sum2 + 1);
        sum2 = -1;
      }
    }
    else{
      sum2 +=a.at(j);
      if (sum2<=0){
        op2 += (-1*sum2 + 1) ;
        sum2 =1 ;
      }
    }
  }

  cout << (op1>op2 ? op2:op1) << endl;
}
