#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,m;
  cin>>n>>m;
  int a=n+m;
  if(a>=24) a-=24;
  cout<<a<<endl;
}