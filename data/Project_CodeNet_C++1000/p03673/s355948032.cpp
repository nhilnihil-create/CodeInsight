#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n; cin>>n;
  string b;
  if(n==1){
    int a; cin>>a;
    cout<<a<<endl;
    return 0;
  }
  vector<string> s(n+1);
  rep(i,n){
    cin>>s[i+1];
  }
  if(n%2==0){
    for(int i=n; i>=2; i-=2){
      cout<<s[i]<<" ";
    }
    for(int i=1; i<=n-1; i+=2){
       cout<<s[i]<<" ";
    }
  }else{
    for(int i=n; i>0; i-=2){
      cout<<s[i]<<" ";
    }
    for(int i=2; i<=n-1; i+=2){
      cout<<s[i]<<" ";
    }
  }
  cout<<endl;
}
