#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
double PI = 3.1415926535897932;
long mod = 1000000007;

int main() {
  int n;
  cin >> n;
  int num[10] = {0}, cnt = 0;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if(a < 400) num[0]++;
    else if(a < 800) num[1]++;
    else if(a < 1200) num[2]++;
    else if(a < 1600) num[3]++;
    else if(a < 2000) num[4]++;
    else if(a < 2400) num[5]++;
    else if(a < 2800) num[6]++;
    else if(a < 3200) num[7]++;
    else cnt++;
  }
  
  int x = 0;
  for(int i = 0; i < 8; i++)
    if(num[i] != 0) x++;

  if(cnt == 0)
    cout << x << " " << x << endl;
  else {
    if(x == 0)
      cout << 1 << " " << cnt << endl;
    else
      cout << x << " " << x+cnt << endl;
  }
}
