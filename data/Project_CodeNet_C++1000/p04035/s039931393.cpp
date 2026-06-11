#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,l; cin>>n>>l;
  int ind;
  vector<int> a(n);
  bool flag=false;
  
  for(int i=0; i<n; i++) cin>>a[i];
  for(int i=0; i<n; i++){
    if(a[i]+a[i+1] >= l){
      flag = true;
      ind = i;
      ind++;
      break;
    }
  }

  if(flag){
    cout<<"Possible"<<endl;
    
    for(int i=n-1; i>ind; i--) cout<<i<<endl;
    for(int i=1; i<ind; i++) cout<<i<<endl;
    cout<<ind<<endl;
  }else
    cout<<"Impossible"<<endl;

  return 0;
}
