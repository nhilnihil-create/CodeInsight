#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
#include <deque>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, K; cin >> N >> K;
  ll A[N], B[N]; FOR(i,0,N) cin >> A[i] >> B[i];
  ll ans = 0;
  // i bit目が1なら0にする場合
  FOR(i,0,32) {
    if((K>>i)&1) {
      // i bit以上はKと同じでないといけない
      ll cnt = 0;
      FOR(j,0,N) {
        bool ok = true;
        if(((A[j]>>i) & 1) == 1) continue;
        FOR(k,i+1,32) {
          if(((K>>k) & 1) == 0 && ((A[j]>>k) & 1) == 1) {
            ok = false;
            break;
          }
        }
        if(ok) cnt += B[j];
      }
      ans = max(ans, cnt);
    }
  }
  ll cnt = 0;
  FOR(j,0,N) {
    bool ok = true;
    FOR(k,0,32) {
      if(((K>>k)&1)==0&&((A[j]>>k)&1)==1) {
        ok = false;
        break;
      }
    }
    if(ok) cnt += B[j];
  }
  cout << max(ans, cnt) << endl;
  return 0;
}