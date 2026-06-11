#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  int a=m,b=m-1;
  for(int i=0;i<n-1;i++){
    a*=b;
  }
  cout << a << endl;
}