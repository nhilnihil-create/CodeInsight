#include <iostream>
#include <string>

#define MAXN 1000000007

typedef long long ll;

using namespace std;

int M[2][52];

ll func ( int N )
{
  ll ans;
  int pos,pre; // 縦:pre = 0, 横:pre = 1

  if ( M[0][0] == M[1][0] ) ans = 3,pos = 1,pre = 0;
  else ans = 6,pos = 2,pre = 1;

  while ( pos < N ) {
    if ( pre == 1 ) {
      if ( M[0][pos] == M[1][pos] ) {
         pos++; pre = 0;
      } else {
        pos += 2; ans *= 3; pre = 1;
      }
    } else {
      if ( M[0][pos] == M[1][pos] ) {
        ans *= 2; ++pos; pre = 0;
      } else {
        ans *= 2; pos += 2; pre = 1;
      }
    }
  }

  return ans % MAXN;
}

int main()
{
  int N;
  string s;

  cin >> N;

  cin >> s;
  for ( int i = 0; i < s.size(); ++i ) M[0][i] = s[i]-'A';

  cin >> s;
  for ( int i = 0; i < s.size(); ++i ) M[1][i] = s[i]-'A';

  cout << func(N) << "\n";
}
