#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
  string x;
  cin>>x;
  int n=x.size();
  int p=0;
  int q=0;
  rep(i,n){
    if(x[i]=='T'&&q==0){
      p++;
    }else if(x[i]=='T'&&q>0){
      p--;
      q--;
    }else if(x[i]=='S'){
      p++;
      q++;
    }
  }
  cout<<p<<endl;
}