#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  int saishou=0;
  int saidai=0;
  int iro1=0;
  int iro2=0;
  int iro3=0;
  int iro4=0;
  int iro5=0;
  int iro6=0;
  int iro7=0;
  int iro8=0;
  int iro9=0;
  for(int i=0;i<n;i++){
    if(a[i]<400)iro1=1;
    else if(a[i]<800)iro2=1;
    else if(a[i]<1200)iro3=1;
    else if(a[i]<1600)iro4=1;
    else if(a[i]<2000)iro5=1;
    else if(a[i]<2400)iro6=1;
    else if(a[i]<2800)iro7=1;
    else if(a[i]<3200)iro8=1;
    else iro9++;
  }
  saishou=iro1+iro2+iro3+iro4+iro5+iro6+iro7+iro8;
  saidai=iro1+iro2+iro3+iro4+iro5+iro6+iro7+iro8+iro9;
  if(saishou==0&&iro9!=0)saishou=1;
  cout<<saishou<<" "<<saidai<<endl;
  return 0;
}
    

