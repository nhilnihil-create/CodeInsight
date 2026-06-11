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
  string s;
  cin >> s;
  for(int i = 0; i < s.size()-1; i++){
    char s1 = s.at(i), s2 = s.at(i+1);
    if(s1 == s2){
      cout << i+1 << ' ' << i+2 << endl;
      return 0;
    }

    if(i+2 < s.size()){
      char s3 = s.at(i+2);
      if(s1 == s3){
        cout << i+1 << ' ' <<  i+3 << endl;
        return 0;
      }
    }
  }
  cout << -1 << ' ' << -1 << endl;
}