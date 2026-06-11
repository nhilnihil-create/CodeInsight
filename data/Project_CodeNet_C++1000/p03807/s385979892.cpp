#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n;
  cin>>n;  
  vector<long>a(n);
  long ans=0;
  rep(i,n){
    cin>>a.at(i);
    ans+=a.at(i);
  }
  if(ans%2==0){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}