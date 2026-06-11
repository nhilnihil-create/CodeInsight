#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  int vec[n+100]={};
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    vec[a]++;
    vec[b]++;
  }
  for(int i=1;i<=n;i++){
    if(vec[i]%2!=0){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
}