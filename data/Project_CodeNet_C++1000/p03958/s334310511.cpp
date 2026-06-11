#include<bits/stdc++.h>
using namespace std;

int main(){
  int k,t;
  cin >> k >> t;
  vector<int>a(t);
  for(int i=0;i<t;i++)cin >> a.at(i);
  sort(a.begin(),a.end(),greater());
  int sum=0;
  for(int i=1;i<t;i++)sum+=a.at(i);
  if(a.at(0)-1<=sum)cout << "0\n";
  else cout << a.at(0)-sum-1 << endl;
  return 0;
}