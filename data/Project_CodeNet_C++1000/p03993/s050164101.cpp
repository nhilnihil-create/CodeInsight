#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう

#define rep(i,n) for(int i=0;i<n;i++)
#define pi       const int pi=3.1415926535
//桁数指定　cout << fixed << setprecision(2)
int main() {
  int ans=0;
  int n;
  cin>>n;
  vector<int> v(n);
  rep(i,n)cin>>v[i];
  rep(j,n){
    if(v[v[j]-1]==j+1)ans++;}
    ans/=2;
A:cout<<ans;    
}