#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  vector<int> l(2*n);
  rep(i, 2*n)cin>>l[i];
  sort(l.begin(), l.end());
  int sum=0;
  rep(i, n)sum+=l[2*i];

  cout<<sum;

  return 0;
}