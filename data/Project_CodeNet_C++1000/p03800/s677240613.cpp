#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
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

int main(void) {
  int n; cin >> n;
  string s; cin >> s;

  int ws[n];
  
  FOR(i,0,1){
    FOR(j,0,1){
      ws[0] = i; ws[1] = j;

      FOR(k,1,n-2){
        if(s[k]=='o' && ws[k]==0) ws[k+1] = ws[k-1];
        else if(s[k]=='o' && ws[k]==1) ws[k+1] = (ws[k-1]+1) % 2;
        else if(s[k]=='x' && ws[k]==0) ws[k+1] = (ws[k-1]+1) % 2;
        else if(s[k]=='x' && ws[k]==1) ws[k+1] = ws[k-1];
      }

      bool ok = true;

      // cout << s[n-1] << " " << ws[n-1] << endl;
      // cout << ws[n-2] << " " << ws[0] << endl;
      // cout << "--------------" << endl;

      if(s[0]=='o' && ws[0]==0) {
        if(ws[n-1]!=ws[1]) ok = false;
      }
      else if(s[0]=='o' && ws[0]==1) {
        if(ws[n-1]==ws[1]) ok = false;
      }
      else if(s[0]=='x' && ws[0]==0) {
        if(ws[n-1]==ws[1]) ok = false;
      }
      else if(s[0]=='x' && ws[0]==1) {
        if(ws[n-1]!=ws[1]) ok = false;
      }

      // cout << ok << endl;

      if(s[n-1]=='o' && ws[n-1]==0) {
        if(ws[n-2]!=ws[0]) ok = false;
      }
      else if(s[n-1]=='o' && ws[n-1]==1) {
        if(ws[n-2]==ws[0]) ok = false;
      }
      else if(s[n-1]=='x' && ws[n-1]==0) {
        if(ws[n-2]==ws[0]) ok = false;
      }
      else if(s[n-1]=='x' && ws[n-1]==1) {
        if(ws[n-2]!=ws[0]) ok = false;
      }

      // cout << ok << endl;

      if(ok){
        FOR(i,0,n-1){
          if(ws[i]==0) cout << 'S';
          else cout << 'W';
        }
        cout << endl;
        return 0;
      }
    }
  }

  cout << -1 << endl;
  return 0;

  

}
