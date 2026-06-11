#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int d=max(a,max(b,c));
  if(d==a+b+c-d) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}