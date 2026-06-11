#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  vector<int>a(k);
  for(int i=0;i<k;i++)cin>>a[i];
  for(int i=n;i<=n*10;i++){
    bool hantei=true;
    int x=i;
    while(x>0){
      int amari=x%10;
      for(int j=0;j<k;j++){
        //cout<<x<<" "<<a[j]<<" "<<amari<<endl;
        if(amari==a[j]){
          hantei=false;
          break;
        }
      }
      x/=10;
      if(hantei==false)break;
    }
    if(hantei==true){
      cout<<i<<endl;
      return 0;
    }
  }
}