#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,sum=0;
  cin>>n;
  int l[n],r[n];
  for(int i=0;i<n;i++){
    cin>>l[i]>>r[i];
    sum = sum+abs(l[i]-r[i])+1;
  }
  cout<<sum<<endl;
} 