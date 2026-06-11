#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  cin >> n >> m;
  
  int a[m],b[m];
  for(int i = 0; i < m; i++){
    cin >> a[i] >> b[i];
  }
  
  int num[n+1];
  for(int i = 0; i < n; i++){
    num[i] = 0;
  }
  for(int i = 0; i < m; i++){
    num[a[i]-1]++;
    num[b[i]-1]++;
  }
  for(int i = 0; i < n; i++){
    cout << num[i] << endl;
  }
  
}