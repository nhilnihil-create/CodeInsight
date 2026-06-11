#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
#define MOD 1000000007LL

int main(){
  int N, M;
  cin >> N >> M;
  int a, b;
  map<int, int> m;
  for(int i = 0; i < M; i++){
    cin >> a >> b;
    if(!m.count(a)) m[a] = 1;
    else m.at(a)++;
    if(!m.count(b)) m[b] = 1;
    else m.at(b) ++;
  }
  bool flag = true;
  for(auto i = m.begin(); i != m.end(); i++){
    int x = i -> second;
    if(x % 2 != 0) flag = false;
  }
  cout << (flag? "YES": "NO") << endl;
}