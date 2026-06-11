#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int x,a,b;
  cin>>x>>a>>b;
  if(a>=b) cout<<"delicious"<<endl;
  else if(b-a<=x) cout<<"safe"<<endl;
  else cout<<"dangerous"<<endl;
}