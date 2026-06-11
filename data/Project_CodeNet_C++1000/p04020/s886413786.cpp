#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int>a(n); 
  rep(i,n){
    cin>>a.at(i);
  }
  long ans=0;
  ans+=a.at(0)/2;
  a.at(0)%=2;
  rep2(i,1,n){
    if(a.at(i)>0&&a.at(i-1)>0){
      ans+=1;
      a.at(i)--;
    }
    ans+=a.at(i)/2;
    a.at(i)%=2;
  }
  cout<<ans<<endl;  
}