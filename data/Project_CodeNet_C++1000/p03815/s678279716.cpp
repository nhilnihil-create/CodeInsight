#include<bits/stdc++.h>
using namespace std;
int main(){
int64_t x;
  cin>>x;
  x--;
  int64_t ans=(x/11)*2;
  if((x%11)<=5)
    cout<<ans+1<<endl;
  else
    cout<<ans+2<<endl;

    return 0;
}