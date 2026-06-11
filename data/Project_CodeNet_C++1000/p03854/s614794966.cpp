#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))

typedef long long ll;

template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const long long INF = 1LL << 60;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string dr = "dream";
  string drr = "dreamer";
  string er = "erase";
  string err = "eraser";
  
  reverse(all(dr));
  reverse(all(drr));
  reverse(all(er));
  reverse(all(err));
  
  string s; cin>>s;
  reverse(all(s));
  
  bool isCont = true;
  int ind = 0;
  string res = "NO";
  
  while(isCont) {
    
    if(s.substr(ind, 5) == dr) {
      ind = ind + 5;
      continue;
    }
    
    if(s.substr(ind, 7) == drr) {
      ind = ind + 7;
      continue;
    }
    
    if(s.substr(ind, 5) == er) {
      ind = ind + 5;
      continue;
    }
    
    if(s.substr(ind, 6) == err) {
      ind = ind + 6;
      continue;
    }
    
    isCont = false;
    res = "NO";
    
  }
  
  if(ind == s.length()) res="YES";
  cout<<res;

  return 0;
}