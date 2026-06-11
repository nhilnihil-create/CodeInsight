#include <bits/stdc++.h>

using namespace std;

int main(){

  long long int x;
  cin>>x;

  long long int cnt=0;

  long long int ans=0;

  if(x%11==0){ 
    cnt = (x/11)*2;
    cout<<cnt<<endl;
  }
  else if(x%11!=0){ 
    cnt=(x/11)*2+2;
    if(((cnt/2)*11)-5<x) cout<<cnt<<endl;
    else if (((cnt/2)*11)-5>=x) cout<<cnt-1<<endl;
  } 
}
