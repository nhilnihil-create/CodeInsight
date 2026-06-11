// includes
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <climits>
#include <bitset>

// macros
#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a); i<(b);++i)
#define rep(i, n) FOR(i, 0, n)

using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;

// solve

int main(int argc, char const* argv[])
{
  string s;
  cin >> s;
  set<char> st;
  vector<int> at;
  for(int i = s.size() - 1; i >= 0; i--){
    st.insert(s[i]);
    if(st.size() == 26){
      at.pb(i);
      st.clear();
    }
  }
  reverse(at.begin(), at.end());
  at.pb(s.size());
  string res = "";
  int start = 0;
  rep(i, at.size()){
    st.clear();
    FOR(j, start, at[i]){
      st.insert(s[j]);
    }
    char t = 'a';
    rep(j, 26){
      if(st.find(char('a' + j)) == st.end()){
        t = char('a' + j);
        break;
      }
    }
    res += t;
    if(i != at.size() - 1){
      FOR(j, at[i], at[i + 1]){
        if(s[j] == t){
          start = j + 1;
          break;
        }
      }
    }
  }
  cout << res << endl;
	return 0;
}
