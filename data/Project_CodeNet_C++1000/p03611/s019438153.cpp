#include <bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<long long> a(1000001,0);
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    if(x>=1)a[x-1]++;
    a[x]++;
    a[x+1]++;
  }
  long long max_num = 0;
  for(int i = 0; i < a.size(); i++)
    max_num = max(max_num,a[i]);  
  
  cout << max_num << endl;
}