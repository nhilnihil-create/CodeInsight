#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main(){
  int n;
  long long int ans=0;
  cin>>n;
  vector<long long int> a(n,0),b(n,0);
  rep(i,n){
    cin>>a.at(i)>>b.at(i);
  }
  int k=0;
  for(int i=n-1;i>=0;i--){
    if(i!=n-1) a.at(i)+=ans;
    k=0;
    (a.at(i)%b.at(i)==0?k=0:k=b.at(i)-(a.at(i)%b.at(i)));
     ans+=k;
  }
  cout<<ans;
}
