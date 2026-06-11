#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int r=0,p;
  
  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    if(r<a){
      r=a;
      p=b;
    }
  }
  
  cout << r+p << endl;
}