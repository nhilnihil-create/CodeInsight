#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  ll n,m;
  cin>>n>>m;
  cout<<min((2*n+m)/4,m/2);
}