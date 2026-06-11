#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> a(N);
  int twb=0;
  int fourb=0;
  for(int i=0; i<N; i++){
    cin >> a.at(i);
    if(a.at(i)%4==0) fourb++;
    else if(a.at(i)%2==0) twb++;
  }
  string ans="No";
  if(fourb>=N/2) ans="Yes";
  if(fourb>=(N-twb+1)/2) ans="Yes";
  if(N==twb) ans="Yes";
  cout << ans << endl;
}