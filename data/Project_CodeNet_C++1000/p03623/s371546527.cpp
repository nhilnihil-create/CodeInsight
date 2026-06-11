#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int x,a,b;
  cin>>x>>a>>b;
  if(abs(x-a)<abs(x-b)) cout<<'A'<<endl;
  else cout<<'B'<<endl;
}