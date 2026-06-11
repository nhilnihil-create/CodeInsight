#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,k,x,y;
  cin>>n>>k>>x>>y;
  cout<<min(n,k)*x+max(0,n-k)*y<<endl;
}