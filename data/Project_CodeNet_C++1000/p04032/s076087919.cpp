#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  string s;
  cin>>s;
  int n=s.size();
  int a=-1;
  int b=-1;
  rep(i,0,n-1){
    if(s[i]==s[i+1]){
      a=i+1;
      b=i+2;
    }
  }
  rep(i,0,n-2){
    if(s[i]==s[i+2]){
      a=i+1;
      b=i+3;
    }
  }
  cout<<a<<' '<<b<<endl;
}