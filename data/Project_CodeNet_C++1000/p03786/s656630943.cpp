#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin>>n;
  long long a[n];
  long long s[n];
  long long suma=0;
  for(long long i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  for(long long i=0;i<n;i++){
    suma=suma+a[i];
    s[i]=suma;
  } 
    
    
  long long cnt=1;
  for(int i=n-1;i>=1;i--){
    if(a[i]<=2*s[i-1]){
      cnt++;
    }
    else break;
  }
  cout<<cnt<<endl;
  return 0;
}

  
    