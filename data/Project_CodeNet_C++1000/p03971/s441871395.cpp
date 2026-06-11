#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i < n; i++)
#define reps(i, n) for(int i=1; i <= n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
using ll=long long;

long mod=1e9+7;


int main() {
  int n,a,b;cin>>n>>a>>b;
  int y=0;
  int kaigai=0;
  rep(i,n){
    char c;cin>>c;
    if(c=='b'){
      kaigai++;
      if(y<a+b&&kaigai<=b)y++,cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
    }
    if(c=='c')cout<<"No"<<endl;
    if(c=='a'){
      if(y<a+b)y++,cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
    }
  }
}

