#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,k;
  cin >>n >>m >>k;
  for(int i=0;i<=n;i++){
    for(int r=0;r<=m;r++){
      int sum=n*r+m*i-2*i*r;
      if(k==sum){cout << "Yes" << endl;
                return 0;}
    }
  }
  cout << "No" << endl;
}