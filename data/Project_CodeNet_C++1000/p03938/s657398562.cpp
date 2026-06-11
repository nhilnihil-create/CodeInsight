#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = pow(10, 9) + 7;
//const int MOD = 998244353;
//const int MOD = ;
int mod(int A, int M) {return (A % M + M) % M;}
const int INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
int divCeil(int A, int B) {return (A + (B - 1)) / B;}
int myctoi(char C) {return C - '0';}
char myitoc(int N) {return '0' + N;}
#define FINALANS(A) {cout << A << endl; exit(0);}

signed main()
{
  int N;
  cin >> N;
  vector<int> p(N);
  for (int i = 0; i < N; i++)
  {
    cin >> p.at(i);
  }

  vector<int> a(N), b(N);
  for (int i = 0; i < N; i++)
  {
    a.at(i) = (i + 1) * N;
    b.at(N - i - 1) = (i + 1) * N;
  }
  for (int i = 0; i < N; i++)
  {
    a.at(p.at(i) - 1) += i;
  }

  for (int i = 0; i < N; i++)
  {
    cout << a.at(i);
    if (i == N - 1)
      cout << endl;
    else
      cout << " ";
  }
  for (int i = 0; i < N; i++)
  {
    cout << b.at(i);
    if (i == N - 1)
      cout << endl;
    else
      cout << " ";
  }
}