#include<bits/stdc++.h>
using namespace std;

int main(){
  long long x,sum=0; cin>>x;
  for(int i=1;;i++){
    sum+=i;
    if(sum>=x){
      cout<<i<<endl;
      return 0;
    }
  }
}