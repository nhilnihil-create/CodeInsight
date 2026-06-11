#include <bits/stdc++.h>
using namespace std;

int main(){
  int K,T;
  cin >> K >> T;
  vector<int> a(T);
  for(int i=0;i<T;i++)  cin >> a.at(i);

  sort(a.begin(),a.end());
  int sum=0;
  for(int i=0;i<T-1;i++)  sum+=a.at(i);
  cout << max(0,a.at(T-1)-sum-1) << endl;

  return 0;
}