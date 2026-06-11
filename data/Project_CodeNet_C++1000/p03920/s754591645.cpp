#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
#define int long long
using namespace std;

main(){
  int n,s=0;
  cin>>n;
  for(int i=1;;i++){
    s+=i;
    if(s>=n){
      int p=i;
      while(n){
        if(n>=p){
          n-=p;
          cout<<p<<endl;
        }
        p--;
      }
      break;
    }
  }
}