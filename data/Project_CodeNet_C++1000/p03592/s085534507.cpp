#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,w,n;
  cin >> h >> w >> n;
  for(int i=0;i<=h;i++){
    for(int j=0;j<=w;j++){
      if(w*i+h*j-2*i*j==n){
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}