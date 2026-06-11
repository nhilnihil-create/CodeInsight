
/*
 * Welcome to my code!
 * -------------------------------------------- *
 * author : lynmisakura(twitter : @andoreiji11)
 */

#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define repn for(int i = 0;i < n;i++)
#define ain(a) for(auto& i : a)cin >> i;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define cont continue

//Simple Array Input
#define SAI int n;cin >> n;vi a(n);ain(a)
//Simple Graph Input
#define SGI(m) for(int i=0;i<m;i++){int a,b;cin >> a >> b;g[--a].pb(--b);g[b].pb(a);}
//Simple Tree Input
#define STI SGI(n-1)

typedef long long ll;
typedef long long integer;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

template<class T> bool chmin(T& a,T b){if(a > b){a = b;return true;}else return false;}
template<class T> bool chmax(T& a,T b){if(a < b){a = b;return true;}else return false;}
template<class T> void print(std::vector<T> a){
    for(int i=0;i<a.size();i++)cout << a[i] << (i < a.size()-1 ? ' ' : '\n');
}


int main(void){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h,w;cin >> h >> w;
  vector<int> cnt(26,0);
  rep(i,h){
    string s;cin >> s;
    for(char x : s)cnt[x - 'a']++;
  }

  int four = (h / 2) * (w / 2);  

  int odd = 0;
  rep(i,26){
    if(cnt[i] % 2 == 1){
      if(++odd > 1){
        cout << "No" << '\n';
        return 0;
      }
      cnt[i]--;
    }
    if(cnt[i] >= 4){
      four -= cnt[i] / 4;
    }
  }  

  if(four <= 0){
    cout << "Yes" << '\n';
  }else{
    cout << "No" << '\n';
  }
  return 0;
}
