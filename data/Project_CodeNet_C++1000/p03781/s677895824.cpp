#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long long x;
bool check(long long a){
  return 1LL*a*(a+1)/2<x;
}
int main(){
	
 	cin>>x;
	long long l =0 ;
  	long long r= 1e6;
  long long ans = 0;
	while(l<=r){
      long long mid = (l+r)/2;
      if(check(mid)){
        l = mid+1;
        ans = mid;
      }else{
        r= mid-1;
      }
    }
  cout<<ans+1<<endl;
}