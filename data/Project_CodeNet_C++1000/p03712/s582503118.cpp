#include <bits/stdc++.h>
using namespace std;

char a[100][100], b[102][102];
int main() {
  int h,w;
  cin >> h >> w;
  for (int i = 0; i < h; i++) scanf("%s",a[i]);
  for (int i = 0; i < h+2; i++) 
    for (int j = 0; j < w+2; j++) 
      b[i][j] = '#';
  for (int i = 0; i < h; i++) 
    for (int j = 0; j < w; j++) 
      b[i+1][j+1] = a[i][j];      
  for (int i = 0; i < h+2; i++) {
    for (int j = 0; j < w+2; j++)  cout << b[i][j];
    cout << endl;
  }
}