#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w,k;
  cin >>h>>w>>k;
  long long maisuu=0;
  for(int i=0;i<=h;i++){
    for(int j=0;j<=w;j++){
      maisuu=i*w-j*i+(h-i)*j;
      if(maisuu==k){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
  cout<<"No"<<endl;
  return 0;
}