#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define fi first
#define se second
#define INF 1000000009
#define LLINF 1000000000000000009LL
using ll = long long;

int main(){
  int x,a,b;
  cin>>x>>a>>b;
  if(b<=a){
    cout<<"delicious"<<endl;
  }
  else if(b<=a+x){
    cout<<"safe"<<endl;
  }
  else{
    cout<<"dangerous"<<endl;
  }
  return(0);
}
