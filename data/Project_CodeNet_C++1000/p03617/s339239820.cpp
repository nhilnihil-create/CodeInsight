#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 1000000009

ll min(ll a,ll b,ll c,ll d){
  if(a < b && a < c && a < d)
    return a;
  else if(b < a && b < c && b < d)
    return b;
  else if(c < a && c < b && c < d)
    return c;
  else
    return d;
}

ll min(ll a,ll b,ll c){
  if(a < b && a < c)
    return a;
  else if(b < a && b < c)
    return b;
  else 
    return c;
}

int main(){
  ll q,h,s,d;
  cin >> q >> h >> s >> d;
  ll n;
  cin >> n;
  ll ans = 0;
  ll qq = 8*q;
  ll hh = 4*h;
  ll ss = 2*s;
  ll firstkey = min(qq,hh,ss,d);
  ll firstans = 0;
  if(firstkey == qq) firstans = q;
  else if(firstkey == hh) firstans = h;
  else if(firstkey == ss) firstans = s;
  else firstans = d;
  ll nn = n / 2;
  ll nnn = n % 2;
  //cout << firstkey << " " << firstans << endl;
  ans += firstkey*nn;
  ll qqq = 4*q;
  ll hhh = 2*h;
  ll secondkey = min(qqq,hhh,s);
  ll secondans = 0;
  if(secondkey == qqq) secondans = q;
  else if(secondkey == hhh) secondans = h;
  else secondans = s;
  //cout << secondkey << " " << secondans << endl;
  ans += secondkey*nnn;
  cout << ans << endl;


}
