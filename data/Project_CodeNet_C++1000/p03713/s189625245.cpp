#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 1000000000000
#define MOD 1000000007
using ll = long long;

int main(){
  int h,w;
  cin >> h >> w;
  ll a = INF, b = INF, c = INF, d = INF;
  if(w>=3)a = h*(w%3!=0);
  if(h>=3)b = w*(h%3!=0);
  if(h%3==2){
    c = max(abs((h/3+1)*w-w/2*(h-(h/3+1))),abs((h/3+1)*w-(w-w/2)*(h-(h/3+1))));
  }else{
    c = max(abs(h/3*w-w/2*(h-h/3)),abs(h/3*w-(w-w/2)*(h-h/3)));
  }
  if(w%3==2){
    d = max(abs((w/3+1)*h-h/2*(w-(w/3+1))),abs((w/3+1)*h-(h-h/2)*(w-(w/3+1))));
  }else{
    d = max(abs(w/3*h-h/2*(w-w/3)),abs(w/3*h-(h-h/2)*(w-w/3)));
  }
  
  cout<<min(a,min(b,min(c,d)))<<endl;
  return 0;
}
