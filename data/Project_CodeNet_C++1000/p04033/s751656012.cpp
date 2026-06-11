#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a>>b;
  long long c=1;
  c*=a;
  c*=b;
  if(c<=0){
    cout << "Zero" << endl;
  }
  else if(a>0&&b>0){
    cout << "Positive" << endl;
  }
  else if((b-a)%2==0){
    cout << "Negative" << endl;
  }
  else{
    cout << "Positive" << endl;
  }
}