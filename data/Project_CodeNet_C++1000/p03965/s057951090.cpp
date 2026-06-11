#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <cstdint>
#include <cmath>
#include <bitset>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

#define N_TIMES(i, n)     for ( uint64_t i = 0;     i <  n; ++i )
#define N_TIMES_REV(i, n) for (  int64_t i = n - 1; i >= 0; --i )

using namespace std;

int main()
{
  string S;
  cin >> S;

  uint64_t N = S.size();
  int64_t k = 0;
  N_TIMES(i, N) {
    if (S[i] == 'g') {
      if ((i % 2) == 0) { // T[i] == 'g'
        
      } else { // T[i] == 'p'
        ++k;
      }
    } else { // S[i] == 'p'
      if ((i % 2) == 0) { // T[i] == 'g'
        --k;
      } else { // T[i] == 'p'
        
      }
    }
  }
  cout << k << endl;

  return 0;
}