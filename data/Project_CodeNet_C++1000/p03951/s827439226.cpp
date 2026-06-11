#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)        for(int i=0; i<(int)(n); ++i)

int main(){
  int n;
  string a,b;
  cin>>n>>a>>b;
  if(a==b){
    cout<<n<<endl;
    return 0;
  }
  if(n==1&&a!=b){
    cout<<2<<endl;
    return 0;
  }
  int kazu=0;
  int saidai=0;
  rep(i,n){
    string bubun=b.substr(0,n-i);
    //cout<<a.substr(i,n-i)<<" "<<bubun<<endl;
    if(b.substr(0,n-i)==a.substr(i,n-i)){
      saidai=max(saidai,n-i);
      //cout<<"OK"<<endl;
    }
  }
  //cout<<saidai<<endl;
  int count=n-saidai;
  cout<<n+count<<endl;
  return 0;
}