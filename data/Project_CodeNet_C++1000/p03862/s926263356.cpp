#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,x;
  cin >>n>>x;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  long long sum=0;
  for(int i=1;i<n;i++){
    int wa=a[i]+a[i-1];
    if(wa>x){
      int hikukazu=wa-x;
      if(hikukazu<=a[i]){
        sum+=hikukazu;
        a[i]-=hikukazu;
      }else{
        sum+=hikukazu;
        a[i]=0;
        a[i-1]=a[i-1]+a[i]-hikukazu;
      }
    }
  }
  cout<<sum<<endl;
  return 0;
}