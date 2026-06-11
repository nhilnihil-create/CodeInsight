#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int w,a,b;
  cin>>w>>a>>b;
  if(a+w<b) cout<<b-a-w<<endl;
  else if(b+w<a) cout<<a-b-w<<endl;
  else cout<<0<<endl;
}