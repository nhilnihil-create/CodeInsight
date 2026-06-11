#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = pow(10, 9) + 7;
//const int MOD = 998244353;
//const int MOD = ;
int mod(int A, int M) {return (A % M + M) % M;}
const int INF = 1LL << 60;
template <class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
int divCeil(int A, int B) {return (A + (B - 1)) / B;}
int myctoi(char C) {return C - 48;}
char myitoc(int N) {return '0' + N;}
 
signed main()
{
  int N, W;
  cin >> N >> W;
  int w0, v0;
  cin >> w0 >> v0;
  vector<vector<int>> V(4);
  V.at(0).push_back(v0);
  for (int i = 1; i < N; i++)
  {
    int w, v;
    cin >> w >> v;
    V.at(w - w0).push_back(v);
  }
  
  vector<vector<int>> S(4);
  for (int i = 0; i < 4; i++)
  {
    sort(V.at(i).begin(), V.at(i).end(), greater<int>());
    S.at(i).push_back(0);
    for (int j = 0; j < V.at(i).size(); j++)
    {
      S.at(i).push_back(S.at(i).at(j) + V.at(i).at(j));
    }
  }
  
  int ans = 0;
  for (int i0 = 0; i0 < S.at(0).size(); i0++)
  {
    for (int i1 = 0; i1 < S.at(1).size(); i1++)
    {
      for (int i2 = 0; i2 < S.at(2).size(); i2++)
      {
        for (int i3 = 0; i3 < S.at(3).size(); i3++)
        {
          int tmp = 0;
          tmp += S.at(0).at(i0);
          tmp += S.at(1).at(i1);
          tmp += S.at(2).at(i2);
          tmp += S.at(3).at(i3);
          cerr << tmp << endl;
          if (w0 * i0 + (w0 + 1) * i1
             + (w0 + 2) * i2 + (w0 + 3) * i3 <= W)
            chmax(ans, tmp);
        }
      }
    }
  }
  
  cout << ans << endl;
}