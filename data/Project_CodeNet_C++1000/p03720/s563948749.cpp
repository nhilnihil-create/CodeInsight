#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> vec(n);
  rep(i,m){
    int a,b;
    cin>>a>>b;
    vec[a-1]++;
    vec[b-1]++;
  }
  rep(i,n){
    cout<<vec[i]<<endl;
  }
}