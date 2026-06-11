#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>

int main() {
  int n;
  cin>>n;
  vector<int>a(n);
  deque<int>k;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(i%2==0){k.push_back(a[i]);}
    else{k.push_front(a[i]);}
  }
  if(n%2!=0){reverse(k.begin(),k.end());}
  for(int i=0;i<n;i++){
    cout<<k[i];
    if(i<n-1){cout<<" ";}
  }cout<<endl;

  return 0;
}