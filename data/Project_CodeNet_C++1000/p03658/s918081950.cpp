#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main()
{
  int N, K, sum=0;
  cin >> N >> K;
  int data[N];

  REP(i, N) cin >> data[i];
  sort(data,data+N,greater<int>());

  REP(i, K) sum += data[i];
  cout << sum << endl;
}
