#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  
  int x[1000000] = {0};
  for(int i = 0; i < n; i++){
    x[a[i]-1]++;
    x[a[i]]++;
    x[a[i]+1]++;
  }
  
  int maxans = 0;
  for(int i = 0; i < 1000000; i++){
    if(x[i] > maxans){
      maxans = x[i];
    }
  }
  
  cout << maxans << endl;
}