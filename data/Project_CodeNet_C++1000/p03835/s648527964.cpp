#include<bits/stdc++.h>
using namespace std;

int main() {
    int k,s,l=0,c=0;
    cin>>k>>s;

    for (int i=0;i<=k;i++){
      for (int j=0 ;j<= k;j++){
      l=s-(i+j) ;
      
        if(0<= l && l <= k )
            c++;
      }
    }
  cout <<c<<"\n";
  return 0;
}