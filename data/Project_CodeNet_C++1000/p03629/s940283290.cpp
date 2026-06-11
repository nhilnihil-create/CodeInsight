
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
using namespace std;
typedef long long ll;

char buf[200000+10];
int nextOccur[26][200000+10];
int lenFrom[200000+10];
int lastFrom[200000+10];

const int INF = 1000000000;

int main(void) {
  scanf("%s", buf);
  int n = strlen(buf);

  REP(c, 26) {
    nextOccur[c][n] = INF;
    for(int i = n-1; i >= 0; --i) {
      if(buf[i] == 'a'+c) {
        nextOccur[c][i] = i;
      } else {
        nextOccur[c][i] = nextOccur[c][i+1];
      }
    }
  }

  for(int i = n-1; i >= 0; --i) {
    int& maxi = lastFrom[i];
    maxi = -1;
    REP(c, 26) {
      maxi = max(nextOccur[c][i], maxi);
    }
    if(maxi == INF){
      lenFrom[i] = 0;
    } else {
      lenFrom[i] = lenFrom[maxi+1]+1;
    }
  }

  for(int pos = 0; ; ) {
    int minLen = INF;
    int minC = -1;
    REP(c, 26) {
      int len = nextOccur[c][pos] == INF ? -1 : lenFrom[nextOccur[c][pos]+1];
      if(len < minLen) {
        minLen = len;
        minC = c;
      }
    }
    
    printf("%c", 'a'+minC);
    if(minLen < 0) {
      break;
    } else {
      pos = nextOccur[minC][pos]+1;
    }
  }
  puts("");
  
  return 0;
}
