#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  vector<int> ab(n);
  rep(i,n)ab[i]=0;
  int result = 0, max_g=0;

  rep(i,n){
    int a,b;cin>>a>>b;
    if(a<max_g)continue;
    max_g=a;
    result = a+b;
  }

  cout<<result;

  return 0;
}