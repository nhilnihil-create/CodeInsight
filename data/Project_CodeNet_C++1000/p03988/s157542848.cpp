#include <iostream>
#include <vector>

using namespace std;

void failure () {
  cout << "Impossible" << endl;
  exit(0);
}

const int MAX_N = 105;

int atds [MAX_N]; // # of vertices with such farthest dist

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int diam = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    atds[x]++;
    diam = max(diam, x);
  }

  if (diam == 1 && n > 2) failure();

  int blw, abv;
  if (diam % 2 == 0) {
    if (atds[diam / 2] != 1) failure();
    blw = diam / 2 - 1;
    abv = diam / 2 + 1;
  } else {
    if (atds[(diam + 1) / 2] != 2) failure();
    blw = diam / 2;
    abv = (diam + 1) / 2;
  }

  for (int i = 0; i <= blw; i++) {
    if (atds[i] > 0) failure();
  }
  for (int i = abv; i <= diam; i++) {
    if (atds[i] < 2) failure();
  }

  cout << "Possible" << endl;
}
