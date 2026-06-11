#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int b[13] = {0};
  
  int a[N];
  int rednum = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    b[a[i] / 400] = 1;
    if (a[i] >= 3200) rednum++;
  }
  
  int colornum = 0;
  for (int i = 0; i < 8; i++) {
    if (b[i]) colornum++;
  }
  if (colornum == 0) {
    cout << 1 << " " << rednum << endl;
  } else {
    cout << colornum << " " << colornum + rednum << endl;
  }
}