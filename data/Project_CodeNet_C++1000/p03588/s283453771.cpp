#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n],b[n],c=0,d;
  for(int i=0;i<n;i++){
    cin >> a[i] >> b[i];
    if(c<a[i]){
      c=a[i];
      d=a[i]+b[i];
    }
  }
  cout << d;
}