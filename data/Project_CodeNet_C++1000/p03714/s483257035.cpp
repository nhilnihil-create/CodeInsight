#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = pow(10, 9) + 7;
//const int MOD = 998244353;
//const int MOD = ;
int mod(int A, int M) {return (A % M + M) % M;}
const int INF = 1LL << 60;
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";
template <class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
int divCeil(int A, int B) {return (A + (B - 1)) / B;}
int myctoi(char C) {return C - 48;}
char myitoc(int N) {return '0' + N;}

signed main()
{
  int N;
  cin >> N;
  vector<int> A(3 * N);
  for (int i = 0; i < 3 * N; i++)
  {
    cin >> A.at(i);
  }
  
  vector<int> P(1, 0);
  priority_queue<int, vector<int>, greater<int>> que0;
  for (int i = 0; i < N; i++)
  {
    P.at(0) += A.at(i);
    que0.push(A.at(i));
  }
  for (int i = N; i < 2 * N; i++)
  {
    int m = que0.top();
    if (m < A.at(i))
    {
      P.push_back(P.back() - m + A.at(i));
      que0.pop();
      que0.push(A.at(i));
    }
    else P.push_back(P.back());
  }
  
  vector<int> Q(1, 0);
  priority_queue<int> que1;
  for (int i = 3 * N - 1; i >= 2 * N; i--)
  {
    Q.at(0) += A.at(i);
    que1.push(A.at(i));
  }
  for (int i = 2 * N - 1; i >= N; i--)
  {
    int M = que1.top();
    if (M > A.at(i))
    {
      Q.push_back(Q.back() - M + A.at(i));
      que1.pop();
      que1.push(A.at(i));
    }
    else Q.push_back(Q.back());
  }
  reverse(Q.begin(), Q.end());
  
  int ans = -INF;
  for (int i = 0; i < N + 1; i++)
  {
    chmax(ans, P.at(i) - Q.at(i));
  }
  
  cout << ans << endl;
}