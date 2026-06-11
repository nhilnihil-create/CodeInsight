#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define SUM(x) accumulate(ALL(x), 0)
#define INF 1000000000000
#define MOD 10000007
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MAXR 100000
#define PI acos(-1.0)

int main()
{
  string S; cin >> S;
  map<int, char> s;
  int N = SIZE(S);
  REP(i, N) s[i] = S[i];

  map<int, char> ans;
  ans[0] = 'C';
  ans[1] = 'O';
  ans[2] = 'D';
  ans[3] = 'E';
  ans[4] = 'F';
  ans[5] = 'E';
  ans[6] = 'S';
  ans[7] = 'T';
  ans[8] = 'I';
  ans[9] = 'V';
  ans[10] = 'A';
  ans[11] = 'L';
  ans[12] = '2';
  ans[13] = '0';
  ans[14] = '1';
  ans[15] = '6';

  int cnt = 0;
  REP(i, N) {
    if (s[i] != ans[i]) cnt++;
  }

  cout << cnt << endl;
  return 0;
}
