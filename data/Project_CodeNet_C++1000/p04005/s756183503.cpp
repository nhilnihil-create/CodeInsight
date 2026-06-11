#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;

int main() {
  ll a,b,c;
  cin>>a>>b>>c;
  if(a%2==0 ||b%2==0 ||c%2==0 ){
    cout<<0<<endl;
  }
  else{
   ll d= max(a,max(b,c));
  ll e=min(a,min(b,c));
   ll f=a+b+c-d-e;
    cout<<e*f<<endl;
  }
}