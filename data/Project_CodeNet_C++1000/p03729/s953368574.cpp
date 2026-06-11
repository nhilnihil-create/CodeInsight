#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  string a,b,c;
  cin>>a>>b>>c;
  if(a[a.size()-1]==b[0] && b[b.size()-1]==c[0]) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}