#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n],k=0,l=999999999;
  for(int i=0;i<n;i++){
    cin >> a[i];
    k+=a[i];
    if(l>a[i]&&a[i]%10!=0)l=a[i];
  }
  if(l==999999999)l=k;
  if(k%10==0)k-=l;
  cout << k;
}
