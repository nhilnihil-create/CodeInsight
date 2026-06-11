#include <bits/stdc++.h>
using namespace std;

int n;
int p[100007];

int main()
{
  cin >> n;
  int count = 0;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  
  for (int i = 0; i < n; i++) {
    if(p[i] == i + 1) {
      count++;
      i++;
    }
  }
  cout << count << endl;
 }