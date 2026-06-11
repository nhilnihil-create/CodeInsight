#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int>t(n);
  vector<int>a(n);
  long takahashi = 0;
  long aoki = 0;
  int i;
  for(i=0;i<n;i++){
    cin >>t[i] >> a[i];
  }
  takahashi = t[0];
  aoki = a[0];
  for(i=1;i<n;i++){
    if(takahashi<=t[i]&&aoki<=a[i]){
      takahashi = t[i];
      aoki = a[i];
    }else{
      if(takahashi%t[i]!=0)takahashi += t[i]-takahashi%t[i];
      if(aoki%a[i]!=0)aoki += a[i]-aoki%a[i];
      if(aoki/a[i]>=takahashi/t[i]){
        takahashi += t[i] * (aoki/a[i] - takahashi/t[i]);
      }else{
        aoki += a[i] * (takahashi/t[i] - aoki/a[i]);
      }
    }
  }
  cout << takahashi+aoki << endl;
}
