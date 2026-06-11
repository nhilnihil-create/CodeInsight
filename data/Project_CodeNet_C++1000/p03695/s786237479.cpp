#include <bits/stdc++.h>
using namespace std;

int main() {
int n;
cin>>n;
vector<int>a(9,0);
for(int i=0;i<n;i++){
  int x;cin>>x;
  if(x<400)a[0]++;
  else if(x<800)a[1]++;
  else if(x<1200)a[2]++;
  else if(x<1600)a[3]++;
  else if(x<2000)a[4]++;
  else if(x<2400)a[5]++;
  else if(x<2800)a[6]++;
  else if(x<3200)a[7]++;
  else a[8]++;
}
int www=0;
for(int i=0;i<8;i++){
  if(a[i])www++;
}
int maxx=max(www,1);
cout<<maxx<<" "<<www+a[8]<<endl;
  return 0;
}

