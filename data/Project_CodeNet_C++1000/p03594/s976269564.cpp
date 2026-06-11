#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define ll long long
#define rep(i,a,n) for(int i = a; i < n; i++)
#define per(i,a,n) for(int i = n-1; i >= a; i--)

char c[4] = {'R','Y','G','B'};

int main() {
  ll H, W, d;
  cin >> H >> W >> d;

  if (d%2) {
    rep(i,0,H) {
      rep(j,0,W) {
        cout << c[2*(i%2)+j%2];
      }
      cout << endl;
    }
  }
  else {
    rep(i,0,H) {
      rep(j,0,W) {
        if ((i+j)%2) {
          ll rr = 500+(i+j+1)/2;
          ll cc = 500+(j-i+1)/2;
          bool br = ((rr%d) >= d/2);
          bool bc = ((cc%d) >= d/2);
          ll ind = 2*br+bc;
          cout << c[ind];
        }
        else {
          ll rr = 500+(i+j)/2;
          ll cc = 500+(j-i)/2;
          bool br = ((rr%d) >= d/2);
          bool bc = ((cc%d) >= d/2);
          ll ind = 2*br+bc;
          cout << c[ind];
        }
      }
      cout << endl;
    }
  }

  return 0;
}
