#include <bits/stdc++.h>
using namespace std;

int main() {
int n;
cin>>n;
vector<int> a(100000,0);
for(int i=0;i<n;i++){
  int x;
  cin>>x;
  a[x]++;
}
int minn =-1;
for(int i=1;i<100000;i++){
  int www=a[i-1]+a[i]+a[i+1];
  minn=max(minn,www);
}
cout<<minn<<endl;
  return 0;
}

