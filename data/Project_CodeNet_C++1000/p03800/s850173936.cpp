#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORL(i,x) for(int i=head[x];i;i=nxt[i])
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back
#define MP make_pair
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
// ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(void){
  int n; cin >> n;
  string s; cin >> s;
  FOR(i,0,1){
    FOR(j,0,1){
      int sw[n];
      sw[0] = i; sw[1] = j;
      FOR(k,1,n-2){
        int tf;
        if(s[k]=='o') tf = 0;
        else tf = 1;

        if(sw[k]==0){
          sw[k+1] = (sw[k-1] + 1 + tf) % 2;
        } else {
          sw[k+1] = (sw[k-1] + tf) % 2;
        }
      }
      bool flag = true;
      bool tf;
      if(s[n-1]=='o') tf = true;
      else tf = false;

      if((sw[n-2]==sw[0]) == tf && sw[n-1]==1){

      } else if((sw[n-2]==sw[0]) != tf && sw[n-1]==0){

      } else {
        flag = false;
      }

      if(s[0]=='o') tf = true;
      else tf = false;

      if((sw[n-1]==sw[1]) == tf && i==1){

      } else if((sw[n-1]==sw[1]) != tf && i==0){

      } else {
        flag = false;
      }
      if(flag){
        FOR(k,0,n-1){
          if(sw[k]==1) cout << "S";
          else cout << "W";
        }
        cout << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;

}