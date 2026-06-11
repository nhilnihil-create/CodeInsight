#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main()
{
  int N, M;
  cin >> N >> M;

  vector<int> T(N);
  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    T.at(a - 1)++;
    T.at(b - 1)++;
  }

  for (int i = 0; i < N; i++)
  {
    cout << T.at(i) << endl;
  }

  return 0;
}