#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define bg begin()
#define en end()

using namespace std;

typedef long long ll;

int N, H, W;
int ans[100][100];
int a[100005];

int main() {
  scanf("%d %d %d", &H, &W, &N);
  rep(i, 1, N+1) scanf("%d", &a[i]);
  
  int num = 1;
  int c = 1;
  rep(i, 0, H) {
    if (i%2 == 0) {
      rep(j, 0, W) {
        ans[i][j] = num;
        if (++c > a[num]) {
          num++;
          c = 1;
        }
      }
    } else {
      per(j, 0, W) {
        ans[i][j] = num;
        if (++c > a[num]) {
          num++;
          c = 1;
        }
      }
    
    }
  
  }
 
  rep(i, 0, H) {
    rep(j, 0, W) {
    if (j > 0) printf(" ");
      printf("%d", ans[i][j]);
    }
    printf("\n");
  }

}