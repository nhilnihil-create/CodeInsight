#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector <int> a(n);
  for (int i=0;i<n;i++) cin>>a.at(i);
  int p=a.at(0),sum=1;
  while(p!=2){
    p=a.at(p-1);
    sum++;
    if (sum>n-1){
      sum=-1;
      break;
    }
  }
    cout<<sum<<endl;
}