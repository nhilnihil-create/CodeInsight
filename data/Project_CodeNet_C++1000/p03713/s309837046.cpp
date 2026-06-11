#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 1000000000


ll gcm(ll a,ll b);
ll lcm(ll a,ll b);
ll fac(ll a);

int main(){
  ll h,w;
  cin >> h >> w;
  vll square(3);
  ll ans = INF;
  rep1(i,h){
    square[0] = i*w;
    if(w%2 == 0){
      square[1] = w/2*(h-i);
      square[2] = w/2*(h-i);
    }
    else{
      square[1] = (w+1)/2*(h-i);
      square[2] = w/2*(h-i);
    }
    sort(square.begin(),square.end());
    if(square[0] != 0)
    	ans = min(ans,square[2] - square[0]);
  }
  rep1(i,h){
    square[0] = i*w;
    if((h-i)%2 == 0){
      square[1] = (h-i)/2*w;
      square[2] = (h-i)/2*w;
    }
    else{
      square[1] = (h-i+1)/2*w;
      square[2] = (h-i)/2*w;
    }
    sort(square.begin(),square.end());
    if(square[0] != 0)
    	ans = min(ans,square[2] - square[0]);
  }
  rep1(i,w){
    square[0] = i*h;
    if(h%2 == 0){
      square[1] = h/2*(w-i);
      square[2] = h/2*(w-i);
    }
    else{
      square[1] = (h+1)/2*(w-i);
      square[2] = h/2*(w-i);
    }
    sort(square.begin(),square.end());
    if(square[0] != 0)
    	ans = min(ans,square[2] - square[0]);
  }
  rep1(i,w){
    square[0] = i*h;
    if((w-i)%2 == 0){
      square[1] = (w-i)/2*h;
      square[2] = (w-i)/2*h;
    }
    else{
      square[1] = (w-i+1)/2*h;
      square[2] = (w-i)/2*h;
    }
    sort(square.begin(),square.end());
    if(square[0] != 0)
    	ans = min(ans,square[2] - square[0]);
  }
  cout << ans << endl;
}