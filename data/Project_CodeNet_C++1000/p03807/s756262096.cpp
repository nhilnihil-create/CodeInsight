#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;cin>>N;
  int odd=0;
  int even=0;
  int x;
  for(int i=0;i<N;i++){
    cin>>x;
    if(x%2==0) even++;
    else odd++;
  }
  bool can=true;
  if(odd%2==1) can=false;
  //else if((odd/2+even)%2==1) can=false;
  if(can) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}